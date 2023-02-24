#include <cstdio>
#include <iostream>
#include <array>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    array<int, 128> hashtable;
    stack<char> numTemp;
    char temp;
    fill(hashtable.begin(), hashtable.end(), 0);
    do{
        temp = getchar();
        numTemp.push(temp);
    }while(temp != '\n');
    numTemp.pop();
    while(!numTemp.empty()){
        if(hashtable[numTemp.top()] == 0){
            printf("%c", numTemp.top());
            hashtable[numTemp.top()] = 1;
        }
        numTemp.pop();
    }
    return 0;
}
// 64 位输出请用 printf("%lld")