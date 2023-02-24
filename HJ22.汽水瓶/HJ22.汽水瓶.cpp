#include <cstdio>
#include <iostream>
using namespace std;

int exchange(int n){
    if(n <= 1){
        return 0;
    }
    else if(n == 2){
        return 1;
    }
    else {
        return n/3 + exchange(n/3 + n % 3);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while(n != 0){
        printf("%d\n", exchange(n));
        scanf("%d", &n);
    }
    return 0;
}
// 64 位输出请用 printf("%lld")