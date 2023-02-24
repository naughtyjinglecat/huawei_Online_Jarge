#include <iostream>
#include <string>
using namespace std;

//马拉车算法
/*遍历的时候，若是中心在半径之外，则从中心向两端检测最大半径；
            若是在右侧半径之内且左侧对应的值未到达边界，则右侧值直接去左侧对应数值即可，
            若是左侧数值达到或者超过边界，则右侧对应数值直接直接从边界向两边检测
            计最大中心maxRadius，最大半径maxRadius，当前点为i，对称点为，2-maxCenter - i,
            (1)如果，dp[2*maxCenter - i] - maxCenter <= maxCenter - maxRadius, 则calmaxRadius(str, i, dp[2*maxCenter - i]);
             */

int caloddRadius(string str, int center){
    int ans = 2;
    int i = center-1, j = center + 2;
    while(i >= 0 && j < str.size() && (str[i] == str[j])){
        i--;
        j++;
        ans += 2;
    }
    return ans;
}
int calevenRadius(string str, int center){
    int ans = 3;
    int i = center - 2, j = center + 2;
    while(i >= 0 && j < str.size() && (str[i] == str[j])){
        i--;
        j++;
        ans += 2;
    }
    return ans;
}


int main() {
    string secret;
    int maxRadius = 1;
    int curRadius = -1;
    cin >> secret;
    for(int i = 1; i < (int)secret.size() - 1; i++){
        if(secret[i] == secret[i + 1]){
            curRadius = caloddRadius(secret, i);
            maxRadius = (maxRadius > curRadius) ? maxRadius : curRadius;
        }
        if(secret[i-1] == secret[i+1]){
            curRadius = calevenRadius(secret, i);
            maxRadius = (maxRadius > curRadius) ? maxRadius : curRadius;
        }
    }
    cout << maxRadius << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")