#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    int n;
    getline(cin, str);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << str[i];
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")inc-expressio