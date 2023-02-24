#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d\n", &n);
    if(n % 2 == 1){
        for(int i = 0; i < n; i++){
            if(i == 0){
                printf("%d", n*n - n/2*2+i*2);
            }
            else{
                printf("+%d", n*n - n/2*2+i*2);
            }
        }
        printf("\n");
    }
    else{
        for(int i = 0; i < n; i++){
            if(i == 0){
                printf("%d", n*n - n+i*2 + 1);
            }
            else{
                printf("+%d", n*n - n+i*2 + 1);
            }
        }
        printf("\n");
    }

    return 0;
}
// 64 位输出请用 printf("%lld")