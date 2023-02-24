#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> strNum;
    char temp = getchar();
    while(temp != '\n'){
        strNum.push(temp);
        temp = getchar();
    }
    while(!strNum.empty()){
        printf("%c", strNum.top());
        strNum.pop();
    }
    printf("\n");
    return 0;
}