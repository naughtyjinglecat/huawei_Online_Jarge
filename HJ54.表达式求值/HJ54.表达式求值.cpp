#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int tag = 1;


/*下次可以试试递归的方法*/


//读取数字并temp返回数字之后的符号
int getInt(char &temp){
    int ans = temp - '0';
    temp = getchar();
    while(temp >= '0' && temp <= '9'){
        ans = ans*10 + temp - '0';
        temp = getchar();
    }
    return ans;
}


int simplyCalculate(int a, int b, char temp){
    switch (temp) {
        case '+': 
            return a + b;
            break;
        case '-': 
            return a - b;
            break;
        case '*': 
            return a * b;
            break;
        case '/': 
            return a / b;
            break;
        default:
            return -1;
    }
}

void checkTag(stack<int> &num, stack<char> &sign){
    int temp = num.top();
    if(tag >= 1){
        if(!sign.empty() && sign.top() == '-'){
            sign.pop();
            num.pop();
            num.push(-temp);
        }
    }
    tag--;
}


int calculate(){
    stack<int> num;
    int n1, n2;
    stack<char> sign;
    char temp = getchar();
    char temp2;
    while(temp != '\n') {
        if(temp >= '0' && temp <= '9'){
            num.push(getInt(temp));
            checkTag(num, sign);
            if(!sign.empty()){
                if(sign.top() == '/' || sign.top() == '*'){
                    n2 = num.top();
                    num.pop();
                    n1 = num.top();
                    num.pop();
                    temp2 = sign.top();
                    sign.pop();
                    num.push(simplyCalculate(n1, n2, temp2));
                    
                }
                else if(sign.top() == '('){
                    continue;
                }
                else{
                    if(temp == '/' || temp == '*' ){
                        continue;
                    }
                    else{
                        n2 = num.top();
                        num.pop();
                        n1 = num.top();
                        num.pop();
                        temp2 = sign.top();
                        sign.pop();
                        num.push(simplyCalculate(n1, n2, temp2));
                    }
                }
            }
            else{
                continue;
            }
        }
        else if(temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '('){
            if(temp == '+' || temp == '-'){
                while(sign.size() != 0 && sign.top() != '('){
                    n2 = num.top();
                    num.pop();
                    n1 = num.top();
                    num.pop();
                    temp2 = sign.top();
                    sign.pop();
                    num.push(simplyCalculate(n1, n2, temp2));
                }
            }
            else if(temp == '('){
                tag++;
            }
            sign.push(temp);
            temp = getchar();
        }
        else{
            tag--;
            while(sign.top() != '('){
                n2 = num.top();
                num.pop();
                n1 = num.top();
                num.pop();
                temp2 = sign.top();
                sign.pop();
                num.push(simplyCalculate(n1, n2, temp2));
            }
            if(sign.top() == '('){
                sign.pop();
            }
            temp = getchar();
            if(temp == '+' || temp == '-'){
                while(sign.size() != 0 && sign.top() != '('){
                    n2 = num.top();
                    num.pop();
                    n1 = num.top();
                    num.pop();
                    temp2 = sign.top();
                    sign.pop();
                    num.push(simplyCalculate(n1, n2, temp2));
                }
            }
        }
    }
    while(!sign.empty()){
        n2 = num.top();
        num.pop();
        n1 = num.top();
        num.pop();
        temp2 = sign.top();
        sign.pop();
        num.push(simplyCalculate(n1, n2, temp2));
    }
    return num.top();
}

int main() {
    printf("%d", calculate());
    return 0;
}
// 64 位输出请用 printf("%lld")