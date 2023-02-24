#include <cstdio>
#include <iostream>
#include <map>
#include <cstdlib>
#include <algorithm>
using namespace std;


//返回数组中最大的数字的下标
int maxNum(int *num, int n){
    int ans = -1;
    int curMaxnum;
    for(int i = 0; i < n; i++){
        if(i == 0){
            curMaxnum = num[0];
            ans = 0;
        }
        else {
            if(curMaxnum < num[i]){
                curMaxnum = num[i];
                ans = i;
            }
        }
    }
    return ans;
}



int main() {
    int n, k;
    int *num;
    int indexMaxnum;
    int  curNum;
    scanf("%d %d", &n, &k);
    num = (int*)malloc(sizeof(int)*k);
    for(int i = 0; i < n; i++){
        if(i < k){
            scanf("%d", num + i);
        }
        else{
            if(i == k){
                indexMaxnum = maxNum(num, k);
            }
            
            scanf("%d", &curNum);
            if(curNum < num[indexMaxnum]){
                num[indexMaxnum] = curNum;
                indexMaxnum = maxNum(num, k);
            }
        }
    }
    sort(num, num + k);
    for(int i = 0; i < k; i++){
        if(i == 0){
            printf("%d", num[i]);
        }
        else{
            printf(" %d", num[i]);
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")