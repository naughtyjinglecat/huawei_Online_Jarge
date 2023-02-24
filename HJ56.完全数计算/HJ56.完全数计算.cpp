#include <iostream>
using namespace std;


//检查一个数是否是完备数
bool checkPerfect(int n){
    int temp = 1;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            temp = temp + i;
            if(i != n){
                temp += n/i;
            }
        }
    }
    if(temp == n){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int n;
    int count = 0;
    cin >> n;
    for(int i = 2; i < n; i++){
        if(checkPerfect(i)){
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
// 64 位输出请用 printf("%lld")