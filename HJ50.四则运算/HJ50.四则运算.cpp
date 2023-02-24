#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

//妈嘞过关嘞哈哈哈哈已呵呵呵呵呵呵


int compute(int a, int b, char sign){
    switch (sign) {
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
            if( b != 0){
                return a / b;
            }
            else{
                return a + 1;
            }
        default:
            return a + 1;
    }
}

int calculation(char str[]){
    int pos;
    int n = 0;
    int a, b;
    char *str2 = NULL;
    int count;
    int size;
    bool tag = false;//标记是否录入过数据，没有就是false，反之true
    bool negative = false;//标记是否遇到了负数，遇到了是true，没有就是false
    stack<int> num;
    stack<char> sign;
    for(pos = 0; str[pos] != '\0'; pos++){
        if(str[pos] >= '0' && str[pos] <='9'){
            tag = true;
            n = n * 10 + str[pos] - '0';
        }
        else{
            switch (str[pos]) {
                case '+':
                    if(negative == true){
                        n *= -1;
                        negative = false;
                    }
                    num.push(n);
                    n = 0;
                    while(!sign.empty()){
                        b = num.top();
                        num.pop();
                        a = num.top();
                        num.pop();
                        num.push(compute(a, b, sign.top()));
                        sign.pop();
                    }
                    sign.push('+');
                    break;
                case '-':
                    if(tag == false){
                        negative = true;
                    }
                    else{
                        if(negative == true){
                            n *= -1;
                            negative = false;
                        }
                        num.push(n);
                        tag = true;
                        n = 0;
                        while(!sign.empty()){
                            b = num.top();
                            num.pop();
                            a = num.top();
                            num.pop();
                            num.push(compute(a, b, sign.top()));
                            sign.pop();
                        }
                        sign.push('-');
                    }
                    break;
                case '*':
                    if(negative == true){
                        n *= -1;
                        negative = false;
                    }
                    num.push(n);
                    tag = true;
                    n = 0;
                    sign.push('*');
                    break;
                case '/':
                    if(negative == true){
                        n *= -1;
                        negative = false;
                    }
                    num.push(n);
                    tag = true;
                    n = 0;
                    sign.push('/');
                    break;
                case '(':
                    count = 0;
                    size = 0;
                    do{
                        if(str[pos] == '(' || str[pos] == '[' || str[pos] == '{'){
                            count++;
                        }
                        else if(str[pos] == ')' || str[pos] == ']' || str[pos] == '}'){
                            count--;
                        }
                        size++;
                        pos++;
                    }while(count != 0);
                    pos--;
                    size -= 2;
                    str2 = new char[size + 1];
                    memcpy(str2, str + pos - size, size);
                    str2[size] = '\0';
                    n = calculation(str2);
                    delete(str2);
                    break;
                case '{':
                    str[pos] = '(';
                    pos--;
                    break;
                case '[':
                    str[pos] = '(';
                    pos--;
                    break;
                case ')':
                    break;
                case '}':
                    break;
                case ']':
                    break;
                case '\0':
                    while(!sign.empty()){
                        b = num.top();
                        num.pop();
                        a = num.top();
                        num.pop();
                        num.push(compute(a, b, sign.top()));
                        sign.pop();
                    }
                    break;
                default:
                    break;
            }
        }
    }
    num.push(n);
    while(!sign.empty()){
        b = num.top();
        num.pop();
        a = num.top();
        num.pop();
        num.push(compute(a, b, sign.top()));
        sign.pop();
    }
    if(num.empty()){
        return 0;
    }
    else{
        return num.top();
    }
}

int main(){
    char str[1005];
    scanf("%s", str);
    printf("%d\n", calculation(str));
    return 0;
}