#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;


//全部变为小写字母


int main() {
    string key, secret, temp;
    cin >> key >> secret;
    bool isused[128];
    char index = 'a';
    map<char, char> letter;
    temp = key;
    fill(isused, isused + 128, false);
    for(int i = 0; i < (int)temp.size(); i++){
        if(isused[temp[i]] == false){
            letter[index] = temp[i];
            index++;
            isused[temp[i]] = true;
        }
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(isused[i] == false){
            letter[index] = i;
            index++;
        }
    }
    for(int i = 0; i < (int)secret.size(); i++){
             cout << letter[secret[i]];
    }
    return 0;
}
// 64 位输出请用 printf("%lld")