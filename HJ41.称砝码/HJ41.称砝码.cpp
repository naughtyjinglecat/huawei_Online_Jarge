#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    set<int> ans;
    set<int> temp2;
    vector<int> weight;
    vector<int> num;
    int n;
    int temp;
    ans.insert(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        weight.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        cin >> temp;
        num.push_back(temp);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < num[i]; j++){
            temp2 = ans;
            for(set<int>::iterator it = temp2.begin(); it != temp2.end(); it++){
                ans.insert(*it + weight[i]);
            }
        }
    }
    cout << ans.size();
    return 0;
}
// 64 位输出请用 printf("%lld")