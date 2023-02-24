#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if(n <= 2){
        printf("-1\n");
    }
    else{
        n -= 2;
        switch (n%4) {
            case 1:
                printf("2\n");
                break;
            case 2:
                printf("3\n");
                break;
            case 3:
                printf("2\n");
                break;
            default:
                printf("4\n");

        }
    }
}
// 64 位输出请用 printf("%lld")