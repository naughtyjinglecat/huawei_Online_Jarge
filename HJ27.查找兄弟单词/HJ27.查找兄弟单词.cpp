#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool testBrother(string a, string b){
    int hashtable[128];
    memset(hashtable, 0, sizeof(hashtable));
    if(a == b){
        return false;
    }
    else{
        for(int i = 0; i < (int)a.size(); i++){
            hashtable[a[i]]++;
        }
        for(int i = 0; i < (int)b.size(); i++){
            hashtable[b[i]]--;
        }
    }
    for(int i = 0; i < 128; i++){
        if(hashtable[i] != 0){
            return false;
        }
    }
    return true;
}

int main() {
    int n, k, count = 0;
    vector<string> brother;
    string temp, wordx, ans;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        brother.push_back(temp);
    }
    sort(brother.begin(), brother.end());
    cin >> wordx >> k;
    for(int i = 0; i < n; i++){
        if(testBrother(wordx, brother[i]) == true){
            count++;
            if(count == k){
                ans = brother[i];
            }
        }
    }
    cout << count << endl;
    if(ans.size() != 0){
        cout << ans << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")