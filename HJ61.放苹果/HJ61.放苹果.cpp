#include <iostream>
#include<stdlib.h>
#include <array>
#include <algorithm>
using namespace std;

/*
如果有m个苹果，n个盘子，有两种情况
如果m >= n
1. 一个空盘子也没有，则转化为(m-n, n),即，将m-n个苹果放在n个盘子里
2.至少有一个空盘子，则相当于吧m个苹果放进n-1个盘子里
(m,n)=(m-n,n)+(m,n-1)
如果m < n,苹果没有盘子多，
则是移除多余的盘子, 使得苹果和盘子一样多,z转化为 m >= n 的情况
*/

//给定盘子不一定放满

int main(void) {
    int apple, plate;
    int **count;
    int itemp, jtemp;
    scanf("%d %d", &apple, &plate);
    if(apple < plate){
        plate = apple;
    }
    count = new int*[apple+1];
    for(int i = 0; i < apple + 1; i++){
        count[i] = new int[plate+1];
        count[i][0] = 0;
        if(plate > 0){
            count[i][1] = 1;
        }
    }
    fill(count[0], count[0]+plate + 1, 1);
    if(apple > 0){
        fill(count[1], count[1]+plate + 1, 1);
    }
    for(int i = 2; i < apple+1; i++){
        itemp = i;
        for(int j = 2; j < plate+1; j++){
            jtemp = j;
            //如果苹果比盘子少，那么移除多余的盘子，转化为苹果不少于盘子情况
            if(itemp < jtemp){
                jtemp = itemp;
            }
            count[i][j] = count[itemp-jtemp][jtemp] + count[itemp][jtemp-1];
        }
    }
    printf("%d\n", count[apple][plate]);
    return 0;
}
// 64 位输出请用 printf("%lld")