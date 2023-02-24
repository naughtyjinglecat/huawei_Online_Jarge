#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    int sign1 = 1;
    int sign2;
    cin >> n;
    for(int i = 0; i < n; i++){
        sign1 += i;
        sign2 = sign1;
        for(int j = i; j < n; j++){
            if(j == i){
                printf("%d", sign2);
            }
            else{
                printf(" %d", sign2);
            }
            sign2 += j + 2;
            
        }
        printf("\n");
    }
    return 0;
}
// 64 位输出请用 printf("%lld")