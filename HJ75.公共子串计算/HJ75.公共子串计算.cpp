#include <iostream>
#include <string>
using namespace std;


/*

思路，

dp[i][j]，长度为i的字符床与长度为j的字符串的最长公共子串
两种情况，最长公共子串包含第j个字符，记包含第j个字符的最长公共子串长度为jmaxlength，
也可能不包含第j个字符，则dp[i][j] = dp[i][j -  1]
综上：dp[i][j] = max(max[i][j-1], jmaxlength)


*/



int maxSubstrlength(string a, string b){
    int itemp, jtemp;
    int maxLength = 0;
    int preMaxlength = 0;
    int jmaxLength = 0, jcurLength = 0;
    for(int i = 0; i < (int)b.size(); i++){
        jmaxLength = 0;
        for(int j = (int)a.size() - 1; j >= 0; j--){
            if(b[i] == a[j]){
                itemp = i;
                jtemp = j;
                jcurLength = 0;
                while(itemp >= 0 && jtemp >= 0 && b[itemp] == a[jtemp]){
                    jcurLength++;
                    itemp--;
                    jtemp--;
                }
                jmaxLength = (jmaxLength > jcurLength) ? jmaxLength : jcurLength;
            }
        }
        preMaxlength = maxLength;
        maxLength = (preMaxlength > jmaxLength) ? preMaxlength : jmaxLength;
    }
    return maxLength;
}

int main() {
    string str1 ,str2;
    cin >> str1 >> str2;
    cout << maxSubstrlength(str1, str2) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")