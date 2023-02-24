#include <cstdio>
#include <iostream>
#include <algorithm>


using namespace std;

void output(int num, bool &tag, int &pre){
    if(tag == false){
        printf("%d", num);
    }
    else {
        if(pre != num){
            printf("%d", num);
        }
    }
    pre = num;
    tag = true;
}
void outputallData(int *num, int n, int p, bool &tag, int &pre){
    for(int i = p; i < n; i++){
        output(num[i], tag, pre);
    }
}

int main() {
    int *num1, *num2;
    int n1, n2;
    int p1 = 0, p2 = 0;
    bool tag = false;
    int pre;
    scanf("%d", &n1);
    num1 = new int[n1];
    for(int i = 0; i < n1; i++){
        scanf("%d", num1+i);
    }
    scanf("%d", &n2);
    num2 = new int[n2];
    for(int i = 0; i < n2; i++){
        scanf("%d", num2+i);
    }
    sort(num1, num1 + n1);
    sort(num2, num2 + n2);
    if(n1 > 0){
        pre = num1[0];
    }
    if(n2 > 0){
        pre = num2[0];
    }
    if(n1 > 0 && n2 > 0){
        pre = num1[0] < num2[0] ? num1[0] : num2[0];
    }
    while(p1 < n1 && p2 < n2){
        if(num1[p1] < num2[p2]){
            output(num1[p1], tag, pre);
            p1++;
        }
        else if(num1[p1] == num2[p2]){
            output(num1[p1], tag, pre);
            p1++;
            p2++;
        }
        else {
            output(num2[p2], tag, pre);
            p2++;
        }
    }
    outputallData(num1, n1, p1, tag, pre);
    outputallData(num2, n2, p2, tag, pre);
    return 0;
}
// 64 位输出请用 printf("%lld")