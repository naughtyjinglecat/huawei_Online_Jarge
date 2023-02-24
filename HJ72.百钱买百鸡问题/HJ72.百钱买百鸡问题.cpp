#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int a;
    scanf("%d", &a);
    for(int i = 0; i <= 20; i++){
        for(int j = 0; j <= 33; j++){
            if(5*i + 3*j > 100){
                break;
            }
            for(int k = 0; k <= 300; k += 3){
                if(5*i + 3*j + k/3 > 100){
                    break;
                }
                else if(5*i + 3*j + k/3 == 100 && i + j + k == 100){
                    printf("%d %d %d\n", i, j ,k);
                }
            }
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")