#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    char temp = '\0';
   string str = "";
    do{
        temp = getchar();
        if((temp >= 'A' && temp <= 'Z') || (temp >= 'a' && temp <= 'z'))
        str.push_back(temp);
        if(temp == ' '){
            str.clear();
        }
    }while(temp != '\n');
    cout << str.size() << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")