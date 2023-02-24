#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

//dp[i] = dp[i-1] + matrix[1].x*matrix[i].y*matrix[i].x, dp[i-2] + matrix[i-1].x*matrix[i].y*matrix[i].x;


typedef struct matrix{
    int x, y;
    matrix(){
        x = -1;
        y = -1;
    }
}matrix;

//a*b
matrix mul(matrix a, matrix b){
    a.y = b.y;
    return a;
}

matrix multiply(vector<matrix> matrixs, int pos, int &ans, string pattern){
    matrix a, b;
    stack<matrix> S;
    int count = 0;
    int letter = 0;
    int num = 0;
    string subpattern;
    for(int i = 0; i < (int)pattern.size(); i++){
        switch (pattern[i])
        {
        case '(':
            count = 0;
            num = 0;
            subpattern.clear();
            for(int j = i; j < (int)pattern.size(); j++){
                letter++;
                if(pattern[j] == '('){
                    count++;
                }
                else if(pattern[j] == ')'){
                    count--;
                }
                else{
                    num++;
                }
                if(count == 0){
                    break;
                }
                if(j != i){
                    subpattern.push_back(pattern[j]);
                }
            }
            S.push(multiply(matrixs, pos, ans, subpattern));
            pos += num;
            i += (letter - 1);
            break;
        case ')':
            while(S.size() >= 2){
                b = S.top();
                S.pop();
                a = S.top();
                S.pop();
                S.push(mul(a, b));
                ans += a.x * b.y * a.y;
            }
        default:
            S.push(matrixs[pos]);
            pos++;
            break;
        }
    }
    while(S.size() >= 2){
        b = S.top();
        S.pop();
        a = S.top();
        S.pop();
        S.push(mul(a, b));
        ans += a.x * b.y * a.y;
    }
    return S.top();
}

int main(){
    int n;
    int ans = 0;
    cin >> n;
    vector<matrix> matrixs(n);
    string pattern;
    for(int i = 0; i < n; i++){
        cin >> matrixs[i].x >> matrixs[i].y;
    }
    cin >> pattern;
    multiply(matrixs, 0, ans, pattern);
    cout << ans << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")