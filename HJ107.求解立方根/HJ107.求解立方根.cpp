#include <cstdio>
#include <iostream>
using namespace std;

#define WUCHA (0.000001)

//计算三次方
double powThree(double n){
    return n*n*n;
}
//计算绝对值
double abss(double n){
    return n < 0 ? (-n) : n;
}
//计算三次方根
double sqrtThree(double n){
    double ans = 0;
    double min = 0, max;
    bool negative = false;
    if(n < 0){
        negative = true;
        n = -n;
    }
    max = n;
    if(n < 1){
        max = 1;
    }
    while(abss(n-powThree(ans)) > WUCHA){
        ans = (max - min) / 2 + min;
        if(powThree(ans) > n){
            max = ans;
        }
        else{
            min = ans;
        }
    }
    if(negative == true){
        ans = -ans;
    }
    return ans;
}

int main() {
    double n;
    cin >> n;
    printf("%.1lf", sqrtThree(n));
    return 0;
}
// 64 位输出请用 printf("%lld")