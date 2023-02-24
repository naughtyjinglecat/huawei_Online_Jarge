#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int computer(int a, int b, char c){
    switch (c) {
        case '+': 
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return 0;
    }
}

bool test(int num, int *n, int count){
    int ans;
    set<int> nums;
    for(int i = 0; i < 4; i++){
        nums.insert(n[i]);
    }
    char sign[4] = {'+', '-', '*', '/'};
    for(int i = 0; i < 4; i++){
        ans = n[i];
        if(nums.size() == 1){
            return false;
        }
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(nums.size() == 1){
                    if(ans == 24){
                        return true;
                    }
                    break;
                }
                if(i == k){
                    continue;
                }
                ans = computer(ans, n[k], sign[j]);
                for(int m = 0; m < 4; m++){
                    for(int p = 0; p < 4; p++){
                        if(nums.size() == 2){
                            if(ans == 24){
                                return true;
                            }
                            break;
                        }
                        if(p == i || p == k){
                            continue;;
                        }
                        ans = computer(ans, n[p], sign[m]);
                        for(int q = 0; q < 4; q++){
                            for(int r = 0; r < 4; r++){
                                if(nums.size() == 3){
                                    if(ans == 24){
                                        return true;
                                    }
                                    break;
                                }
                                if(r == i || r == k || r == p){
                                    continue;
                                }
                                ans = computer(ans, n[r], sign[q]);
                                if(ans == 24){
                                    return true;
                                }
                            }
                        }
                    }
                }
            }
        }
    }    
    return false;
}

int main() {
    int n[4];
    cin >> n[0] >> n[1] >> n[2] >> n[3];
    sort(n, n + 4);
    if(test(24, n, 4) == true){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    return 0;
}
// 64 位输出请用 printf("%lld")