#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int times[26];

bool cmp(char a, char b){
    return times[a - 'a'] > times[b - 'a'];
}

int main() {
    char letter[26];
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        memset(times, 0, sizeof(times));
        char temp = getchar();
        int ans = 0;
        while(temp != '\n'){
            if(temp >= 'A' && temp <= 'Z'){
                temp = temp - 'A' + 'a';
            }
            times[temp - 'a']++;
            temp = getchar();
        }
        for(int i = 0; i < 26; i++){
            letter[i] = 'a' + i;
        }
        sort(letter, letter + 26, cmp);
        for(int i = 0; i < 26; i++){
            ans += (times[letter[i] - 'a'] * (26 - i));
        }
        cout << ans << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")