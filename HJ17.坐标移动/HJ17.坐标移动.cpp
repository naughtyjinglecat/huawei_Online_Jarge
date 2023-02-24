#include <iostream>
#include <string>
using namespace std;

bool check(string str, int i){
    char temp;
    if(str[i] >= 'A' && str[i] <= 'Z' && i+1 < str.size()){
        temp = str[i + 1];
        i++;
        while(temp >= '0' && temp <= '9' && i < str.size()){
            temp = str[i];
            i++;
        }
        if(temp != ';'){
            return false;
        }
        return true;
    }
    return false;
}

int getNum(string str, int i){
    int ans = 0;
    if(i + 1 < str.size()){
        i++;
        while(i < str.size() && str[i] >= '0' && str[i] <= '9'){
            ans = ans*10 + str[i] - '0';
            i++;
        }
    }
    return ans;
}

int main() {
    string str;
    int x = 0, y = 0;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++){
        if(i == 0){
            if(check(str, i)){
                switch (str[i]) {
                    case 'A':
                        x -= getNum(str, i);
                        break;
                    case 'D':
                        x += getNum(str, i);
                        break;
                    case 'S':
                        y -= getNum(str, i);
                        break;
                    case 'W':
                        y += getNum(str, i);
                        break;
                    default:
                        break;
                }
            }
        }
        else{
            if(check(str, i) && str[i-1] == ';'){
                switch (str[i]) {
                    case 'A':
                        x -= getNum(str, i);
                        break;
                    case 'D':
                        x += getNum(str, i);
                        break;
                    case 'S':
                        y -= getNum(str, i);
                        break;
                    case 'W':
                        y += getNum(str, i);
                        break;
                    default:
                        break;
                }
            }
        }
    }
    cout << x << ',' << y <<endl;
    return 0;
}
// 64 位输出请用 printf("%lld")