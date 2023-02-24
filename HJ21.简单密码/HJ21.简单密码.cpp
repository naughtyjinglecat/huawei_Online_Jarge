#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;

char transform1(char temp){
    if(temp >= 'a' && temp <= 'c'){
        return '2';
    }
    else if(temp >= 'd' && temp <= 'f'){
        return '3';
    }
    else if(temp >= 'g' && temp <= 'i'){
        return '4';
    }
    else if(temp >= 'j' && temp <= 'l'){
        return '5';
    }
    else if(temp >= 'm' && temp <= 'o'){
        return '6';
    }
    else if(temp >= 'p' && temp <= 's'){
        return '7';
    }
    else if(temp >= 't' && temp <= 'v'){
        return '8';
    }
    else{
        return '9';
    }
}
char transform2(char temp){
    if(temp == 'Z'){
        return 'a';
    }
    return temp - 'A' + 'a' + 1;
}

int main() {
    char temp = getchar();
    while(temp != '\n'){
        if(temp >= 'a' && temp <= 'z'){
            printf("%c", transform1(temp));
        }
        else if(temp >= 'A' && temp <= 'Z'){
            printf("%c", transform2(temp));
        }
        else {
            printf("%c", temp);
        }
        temp = getchar();
    }
    printf("\n");
    return 0;
}
// 64 位输出请用 printf("%lld")