
#include <cstdio>
#include <iostream>
#include <cstring>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 128> hashtable;
    char temp = '\0';
    fill(hashtable.begin(), hashtable.end(), 0);
    do{
        temp = getchar();
        hashtable[temp]++;
    }while(temp != '\n');
    scanf("%c", &temp);
    if(temp >= 'a' && temp <= 'z'){
        cout << hashtable[temp] + hashtable[temp - 'a' + 'A'];
    }
    else if(temp >= 'A' && temp <= 'Z'){
        cout << hashtable[temp] + hashtable[temp - 'A' + 'a'];
    }
    else {
        cout << hashtable[temp];
    }
    return 0;
}
// 64 位输出请用 printf("%lld")