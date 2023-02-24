#include <cstdio>
#include <iostream>
#include <array>
using namespace std;

int main() {
    getchar();
    getchar();
    int ans = 0;
    char temp = getchar();
    while(temp != '\n'){
        ans *= 16;
        if(temp >= '0' && temp <= '9'){
            ans += temp - '0';
        }
        else {
            ans += 10;
            ans += temp - 'A';
        }
        temp = getchar();
    }
    printf("%d", ans);
    return 0;
}
// 64 位输出请用 printf("%lld")