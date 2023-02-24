#include <cstdio>
#include <iostream>
using namespace std;

//时间复杂度是O(n),但是空间复杂度貌似是O(1)

int main() {
    int song;
    char temp;
    int p = 1;
    int window = 1;
    scanf("%d\n", &song);
    temp = getchar();
    while(temp != '\n'){
        switch (temp) {
            case 'U':
                if(song > 4 && window == p){
                    if(p != 1){
                        window--;
                    }
                    else{
                        window = song - 3;
                    }
                }
                p--;
                if(p == 0){
                    p = song;
                }
                break;
            case 'D':
                if(song > 4 && window == p -3){
                    if(p != song){
                        window++;
                    }
                    else {
                        window = 1;
                    }
                }
                p++;
                if(p == song + 1){
                    p = 1;
                }
                break;
            default:
                cout << "somethingWrong!" << endl;
                break;
        }
        temp = getchar();
    }
    if(song <= 4){
        for(int i = 1; i <= song; i++){
            if(i == song){
                cout << i << endl;
            }
            else{
                cout << i << ' ';
            }
        }
    }
    else{
        for(int i = window; i < window + 4; i++){
            if(i == window + 3){
                cout << i << endl;
            }
            else{
                cout << i << ' ';
            }
        }
    }
    cout << p;
    return 0;
}
// 64 位输出请用 printf("%lld")