#include <cstdio>
#include <iostream>
using namespace std;


//闰年4年一次，但是逢公元百年不置润
int main() {
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDay = 0;
    int year, month, day;
    scanf("%d %d %d\n", &year, &month, &day);
    if(year % 4 == 0 && year % 100 != 0){
        months[2] = 29;
    }
    for(int i = 1; i <= month - 1; i++){
        totalDay += months[i];
    }
    printf("%d\n", totalDay + day);
    return 0;
}
// 64 位输出请用 printf("%lld")