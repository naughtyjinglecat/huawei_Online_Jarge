#include <iostream>
using namespace std;

int main() {
    int ip1[4];
    unsigned long long ip = 0;
    int ip5, ip6, ip7, ip8;
    scanf("%d.%d.%d.%d", ip1, ip1 + 1, ip1 +2, ip1 + 3);
    for(int i = 0; i < 4; i++){
        ip = ip * 256 + ip1[i];
    }
    cout << ip << endl;
    cin >> ip;
    for(int i = 3; i >= 0; i--){
        ip1[i] = ip % 256;
        ip /= 256;
    }
    printf("%d.%d.%d.%d\n", ip1[0], ip1[1], ip1[2], ip1[3]);
    return 0;
}
// 64 位输出请用 printf("%lld")