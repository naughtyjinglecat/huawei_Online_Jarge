#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



//dp数组，dp[i][j],第长度为i的str1与长度为j的str2的字符串距离计算
//dp[i][j],若是d当前str1若是移去一个字符，就可以变为dp[i-1][j],或是str2移去一个字符，就可变为dp[i][j-1]的情况，
//此时,dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1)



int main() {
    int **dp;
    string str1, str2;
    cin >> str1 >> str2;
    dp = new int*[(int)str1.size() + 1];
    for(int i = 0; i < (int)str1.size() + 1; i++){
        dp[i] = new int[str2.size() + 1];
        dp[i][0] = i;
    }
    for(int i = 0; i < str2.size() + 1; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i < (int)str1.size()+1; i++){
        for(int j = 1; j < str2.size()+1; j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];
            }
            else{
                dp[i][j] = min(dp[i-1][j] + 1, min(dp[i][j-1] + 1, dp[i-1][j-1] + 1));
            }
        }
    }
    cout << dp[str1.size()][str2.size()] << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")