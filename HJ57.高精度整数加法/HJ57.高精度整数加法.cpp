#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;

string add(string str1, string str2){
    string ans;
    int a = 0, b = 0;
    int CF = 0;//进位标志
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    for(int i = 0; i < str1.size() || i < str2.size(); i++){
        // a = (str1.size() < i) ? 0 : str1[i] - '0';
        // b = (str2.size() < i) ? 0 : str2[i] - '0';
        a = (i < str1.size()) ? (str1[i] - '0') : 0;
        b = (i < str2.size()) ? (str2[i] - '0') : 0;
        ans.push_back((a + b + CF) % 10 + '0');
        if(a + b + CF >= 10){
            CF = 1;
        }
        else{
            CF = 0;
        }
    }
    if(CF == 1){
        ans.push_back('1');
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << add(str1, str2);
    return 0;
}
// 64 位输出请用 printf("%lld")