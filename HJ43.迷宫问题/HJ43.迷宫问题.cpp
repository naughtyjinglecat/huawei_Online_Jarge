#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;



typedef struct xy{
    int x, y;
    xy(){
        x = 0;
        y = 0;
    }
    xy(int _x, int _y){
        x = _x;
        y = _y;
    }
}xy;

int **num;
stack<xy> S;
void DFS(int x, int y, int n, int m){
    xy temp(x, y);
    S.push(temp);
    num[x][y] = 2;
    if(x - 1 >= 0 && num[x - 1][y]  == 0){
        DFS(x - 1, y, n, m);
    }
    if(x + 1 < n && num[x + 1][y]  == 0){
        DFS(x + 1, y, n, m);
    }
    if(y - 1 >= 0 && num[x][y - 1]  == 0){
        DFS(x, y - 1, n, m);
    }
    if(y + 1 < m && num[x][y + 1]  == 0){
        DFS(x, y + 1, n, m);
    }
    if(!(S.top().x == n - 1 && S.top().y == m - 1)){
        S.pop();
    }
}

int main() {
    int n, m;
    xy temp1;
    stack<xy> St;
    cin >> n >> m;
    num = new int*[n];
    for(int i = 0; i < n; i++){
        num[i] = new int[m];
        for(int j = 0; j < m; j++){
            cin >> num[i][j];
        }
    }
    xy temp2(0, 0);
    // S.push(temp2);
    DFS(0, 0, n, m);
    while(!S.empty()){
        St.push(S.top());
        S.pop();
    }
    while(!St.empty()){
        printf("(%d,%d)\n", St.top().x, St.top().y);
        St.pop();
    }
    for(int i = 0; i < n; i++){
        delete(num[i]);
    }
    delete(num);
    return 0;
}
// 64 位输出请用 printf("%lld")