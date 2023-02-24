#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


bool isLetter(char a){
    if(a >= 'a' && a <= 'z'){
        return true;
    }
    else if(a >= 'A' && a <= 'Z'){
        return true;
    }
    else{
        return false;
    }
}

bool cmp(char *a, char *b){
    char a1 = *a, b1 = *b;
    if(a1 >= 'A' && a1 <= 'Z'){
        a1 = a1 - 'A' + 'a';
    }
    if(b1 >= 'A' && b1 <= 'Z'){
        b1 = b1 - 'A' + 'a';
    }
    if(a1 != b1){
        return a1 < b1;
    }
    else{
        return (unsigned long long)a < (unsigned long long)b;
    }
}

int main() {
    char str[1005];
    char *letter[1005];
    int countLetter = 0;
    int j = 0;
    scanf("%[^\n]", str);
    for(int i = 0; i < (int)strlen(str); i++){
        if(isLetter(str[i])){
            letter[countLetter] = str + i;
            countLetter++;
        }
    }
    sort(letter, letter + countLetter, cmp);
    for(int i = 0; i < (int)strlen(str); i++){
        if(isLetter(str[i])){
            printf("%c", *letter[j]);
            j++;
        }
        else{
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
// 64 位输出请用 printf("%lld")