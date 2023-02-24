#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int hashtable[128];
    fill(hashtable, hashtable + 128, 0);
    string n;
    int i;
    cin >> n;
    for(i = 0; i < (int)n.size(); i++){
        hashtable[n[i]]++;
    }
    for(i = 0; i < (int)n.size(); i++){
        if(hashtable[n[i]] == 1){
            cout << n[i] << endl;
            break;
        }
    }
    if(i == (int)n.size()){
        cout << "-1" << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")