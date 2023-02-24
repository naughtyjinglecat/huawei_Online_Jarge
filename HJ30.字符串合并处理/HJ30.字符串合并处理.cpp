#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int hashtable[128];
char hashtable2[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

void inithashtable(int *hashtable){
    for(int i = 0; i < 10; i++){
        hashtable['0' + i] = i;
    }
    for(char i = 'a'; i <= 'f'; i++){
        hashtable[i] = 10 + i - 'a';
    }
    for(char i = 'A'; i <= 'F'; i++){
        hashtable[i] = 10 + i - 'A';
    }
}

//字符转化为二进制
string CTB(char a){
    string ans;
    int temp;
    if((a >= '0' && a <= '9') || (a >= 'A' && a <= 'F') || (a >= 'a' && a <= 'f')){
        temp = hashtable[a];
        for(int i = 0; i < 4; i++){
            if(temp != 0){
                ans.push_back(temp % 2 + '0');
                temp /= 2;
            }
            else{
                ans.push_back('0');
            }
        }
        reverse(ans.begin(), ans.end());
    }
    else{
        ans.push_back(a);
    }
    return ans;
}
char BTC(string a){
    int ans = 0;
    if(a.size() == 1){
        return a[0];
    }
    reverse(a.begin(), a.end());
    for(int i = 0; i < (int)a.size(); i++){
        if(a[i] == '1'){
            ans = ans * 2 + 1;
        }
        else{
            ans = ans * 2;
        }
    }
    return hashtable2[ans];
}
int main() {
    string str1, str2;
    vector<char> temp1, temp2;
    inithashtable(hashtable);
    cin >> str1 >> str2;
    str1= str1 + str2;
    for(int i = 0; i < (int)str1.size(); i += 2){
        temp1.push_back(str1[i]);
    }
    for(int i = 1; i < (int)str1.size(); i += 2){
        temp2.push_back(str1[i]);
    }
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    str2 = "";
    for(int i = 0; i < (int)str1.size(); i++){
        if(i % 2 == 0){
            str2.push_back(BTC(CTB(temp1[i/2])));
        }
        else{
            str2.push_back(BTC(CTB(temp2[i/2])));
        }
    }
    cout << str2;
    return 0;
}
// 64 位输出请用 printf("%lld")