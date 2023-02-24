#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*动态规划：
空字符串的最长公共子串长度为0，
字符串都非空的时候：
要么当前字符在最大公共子串中，要么当前字符不在最大公共子串中，要么是当前最长子串的最后一个字母
dp[i] = max(dp[i-1], curmaxlength),
优化一下，可以节省一下空间，只用常数级的空间即可

*/

string maxCommonlength(string a, string b){
    string ans;
    int pos = 0, pospre = 0, curpos = 0; //curpos记录的是若包含当前字符，则其实子串的位置
    int dppre = 0, dpcur = 0;
    int curmaxLength = 0, curlength = 0;
    if(a.size() > b.size()){
        swap(a, b);
    }
    for(int i = 0; i < (int)a.size(); i++){
        //包含当前字符的话，查找最长匹配子串长度
        for(int j = (int)b.size() - 1; j >= 0; j--){
            if(a[i] == b[j]){
                int itemp = i, jtemp = j;
                curlength = 0;
                while(itemp >= 0 && jtemp >= 0){
                    if(a[itemp] == b[jtemp]){
                        curlength++;
                    }
                    else{
                        if(curmaxLength < curlength){
                            curmaxLength = curlength;
                            curpos = jtemp + 1;
                        }
                        break;
                    }
                    itemp--;
                    jtemp--;
                }
                if(curmaxLength < curlength){
                    curmaxLength = curlength;
                    curpos = jtemp + 1;
                }
            }
        }
        if(dppre > curmaxLength){
            dpcur = dppre;
            pos = pospre;
        }
        else{
            dppre = dpcur;
            dpcur = curmaxLength;
            pospre = pos;
            pos = curpos;
        }
    }
    ans = b.substr(pos, dpcur);
    return ans;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    cout << maxCommonlength(str1, str2);
    
    return 0;
}
// 64 位输出请用 printf("%lld")