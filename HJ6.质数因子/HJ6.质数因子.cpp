#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int firstFactor(int n);
void allFactor(int n);

int main() {
    long long n = 0;
    long long i = 3610;
    bool tag = true;
    scanf("%lld", &n);
    allFactor(n);
    return 0;
}
// 64 位输出请用 printf("%lld")

int firstFactor(int n){
    if(n % 2 == 0){
        return 2;
    }
    for(int i = 3; i*i <= n; i += 2){
        if(n % i == 0){
            return i;
        }
    }
    return n;
}

void allFactor(int n){
    int temp = firstFactor(n);
    printf("%d", temp);
    n /= temp;
    while(n != 1){
        temp = firstFactor(n);
        n /= temp;
        printf(" %d", temp);
    }
    printf("\n");
}