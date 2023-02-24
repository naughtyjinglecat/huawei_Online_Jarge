#include <iostream>
#include <set>
#include <array>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//a在b中，则返回true，否则返回false

string inttoStr(int n){
    string ans;
    if(n == 0){
        ans.push_back('0');
    }
    while(n != 0){
        ans.push_back('0' + n % 10);
        n /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool numinNum(int a, int b){
    string a1 = inttoStr(a);
    string b1 = inttoStr(b);
    bool sign = false;
    for(int i = 0; i < (int)b1.size() - (int)a1.size() + 1; i++){
        for(int j = 0; j < (int)a1.size(); j++){
            if(b1[i + j] == a1[j]){
                if(j == (int)a1.size()-1){
                    return true;
                }
                continue;
            }
            else {
                break;
            }
        }
    }
    return false;
}


int main() {
    int *I;
    set<int> R;
    int temp;
    int ni, nr;
    vector<int> output;
    bool sign = false;
    int index;
    cin >> ni;
    I = new int[ni];
    for(int i = 0; i < ni; i++){
        cin >> I[i];
    }
    cin >> nr;
    for(int i = 0; i < nr; i++){
        cin >> temp;
        R.insert(temp);
    }
    output.push_back(0);
    for(set<int>::iterator it = R.begin(); it != R.end(); it++){
        sign = false;
        output.push_back(*it);
        output.push_back(0);
        index = (int)output.size() - 1;
        output[0] += 2;
        for(int i = 0; i < ni; i++){
            if(numinNum(*it, I[i])){
                output.push_back(i);
                output.push_back(I[i]);
                output[0] += 2;
                output[index]++;
                sign = true;
            }
        }
        if(sign == false){
            output.pop_back();
            output.pop_back();
            output[0] -= 2;
        }
    }
    cout << output[0];
    for(int i = 1; i < (int)output.size(); i++){
        cout << ' ' << output[i];
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")