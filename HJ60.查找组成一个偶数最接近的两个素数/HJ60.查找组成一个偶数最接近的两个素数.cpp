#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int nextPrime(int *num, int n, int front){
    int i = 0;
    for(i = front+1; i <= n; i++){
        if(num[i] == 0){
            return i;
        }
    }
    return n;
}
int prePrime(int *num, int n, int rear){
    for(int i = rear-1; i >= 2; i--){
        if(num[i] == 0){
            return i;
        }
    }
    return 1;
}

int main() {
    int *prime = NULL;//质数标0，合数标1
    int n;
    int front, rear;
    int finalFront, finalRear;
    int curdistance;
    scanf("%d", &n);
    prime = new int[n+1];
    fill(prime, prime + n + 1, 0);
    for(int i = 2; i <= n; i++){
        if(prime[i] == 0){
            for(int j = 2; j*i <= n; j++){
                prime[j*i] = 1;
            }
        }
    }
    front = 2;
    rear = prePrime(prime, n, n);
    curdistance = rear - front;
    while(front <= rear){
        if(front + rear > n){
            rear = prePrime(prime, n, rear);
        }
        else if(front + rear < n){
            front = nextPrime(prime, n, front);
        }
        else{
            finalFront = front;
            finalRear = rear;
            front = nextPrime(prime, n, front);
            rear = prePrime(prime, n, rear);
        }
    }
    printf("%d\n%d\n", finalFront, finalRear);
    return 0;
}
// 64 位输出请用 printf("%lld")