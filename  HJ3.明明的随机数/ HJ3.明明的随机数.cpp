#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    int temp = -1;
    int n = 0;
    array<int, 1005> hashtable;
    fill(hashtable.begin(), hashtable.end(), 0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        if(hashtable[temp] == 0){
            hashtable[temp] = 1;
        }
    }
    for(int i = 0; i < 1005; i++){
        if(hashtable[i] == 1){
            cout << i << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")