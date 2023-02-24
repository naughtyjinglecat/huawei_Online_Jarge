#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    int count = 0;
    int temp;
    scanf("%d", &num);
    for(int i = 30; i >= 0; i--){
        temp = pow(2, i);
        if(num >= temp){
            num -= temp;
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
// 64 位输出请用 printf("%lld")