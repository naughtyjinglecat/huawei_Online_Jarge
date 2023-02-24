#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int i = 0;
    char temp = '\0';
    temp = getchar();
    while(temp != '\n'){
        printf("%c", temp);
        i++;
        i %= 8;
        if(i == 0){
            printf("\n");
        }
        temp = getchar();
    }
    while (i != 0) {
        printf("0");
        i++;
        i %= 8;
        if(i == 0){
            printf("\n");
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")