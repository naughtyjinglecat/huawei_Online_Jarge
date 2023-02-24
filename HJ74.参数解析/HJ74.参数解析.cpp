#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int main() {
    int n = 0;
    queue<string> Q;
    char p = getchar();
    string keyWord;
    while(p != '\n'){
        switch(p){
            case ' ':
            Q.push(keyWord);
            keyWord.clear();
            n++;
                break;
            case '"':
                do{
                    p = getchar();
                    if(p != '"'){
                        keyWord.push_back(p);
                    }
                }while(p != '"');
                break;
            default:
                keyWord.push_back(p);
        }
        p = getchar();
    }
    if(!keyWord.empty()){
        Q.push(keyWord);
        n++;
    }
    cout << n << endl;
    while(!Q.empty()){
        cout << Q.front() << endl;
        Q.pop();
    }
    return 0;
}
// 64 位输出请用 printf("%lld")