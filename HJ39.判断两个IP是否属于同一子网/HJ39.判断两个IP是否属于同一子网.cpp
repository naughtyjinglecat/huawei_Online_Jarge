#include <iostream>
using namespace std;


//合法返回true，非法返回false
bool checkMask(int *mask){
    long long temp = 0;
    int count = 32;
    if((mask[0] >= 0 && mask[0] <= 255) &&(mask[1] >= 0 && mask[1] <= 255) && (mask[2] >= 0 && mask[2] <= 255 )&& (mask[3] >= 0 && mask[3] <= 255)){
        for(int i = 0; i < 4; i++){
            temp = temp * 256 + mask[i];
        }
        while(temp % 2 == 0){
            temp /= 2;
            count--;
        }
        while(temp % 2 == 1){
            temp /= 2;
            count--;
        }
        if(temp == 0 && count == 0){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool checkip(int *ip){
    if((ip[0] >= 0 && ip[0] <= 255) &&(ip[1] >= 0 && ip[1] <= 255) && (ip[2] >= 0 && ip[2] <= 255 )&& (ip[3] >= 0 && ip[3] <= 255)){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    int mask[4];
    int ip1[4], ip2[4];
    bool sign = false;
    scanf("%d.%d.%d.%d", mask, mask + 1, mask + 2, mask + 3);
    scanf("%d.%d.%d.%d", ip1, ip1 + 1, ip1 + 2, ip1 + 3);
    scanf("%d.%d.%d.%d", ip2, ip2 + 1, ip2 + 2, ip2 + 3);
    if(checkMask(mask) == false || checkip(ip1) == false || checkip(ip2) == false){
        cout << 1 << endl;
    }
    else{
        for(int i = 0; i < 4; i++){
            ip1[i] = ip1[i]&mask[i];
            ip2[i] = ip2[i]&mask[i];
        }
        for(int i = 0; i < 4; i++){
            if(ip1[i] != ip2[i]){
                sign = true;
            }
        }
        if(sign == false){
            cout << 0 << endl;
        }
        else{
            cout << 2 << endl;
        }
        
    }
    return 0;
}
// 64 位输出请用 printf("%lld")