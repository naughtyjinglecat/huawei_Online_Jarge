#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main(void) {
    array<int, 128> hashTable;
    int ans = 0;
    fill(hashTable.begin(), hashTable.end(), 0);
    char temp = getchar();
    while(temp != '\n'){
        if(hashTable[temp] == 0){
            hashTable[temp] = 1;
            ans++;
        }
        temp = getchar();
    }
    printf("%d\n", ans);
    return 0;
}
// 64 位输出请用 printf("%lld")