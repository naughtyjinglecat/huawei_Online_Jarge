#include<iostream>
#include<queue>
#include<stack>
#include<set>
#include<string>
using namespace std;


/*
队列Q1是即将进站队列，S火车站，Q2是已经出站队列，
每次火车进站之后，都有两种选择，要么立刻出站 ，要么暂时不出站，
如果不出站，则进入下一次递归，等待下一辆火车出站，如果出站，则他之前为出站的火车会获取一次出站机会

特别的，如果是最后一辆进站火车只能选择立刻出站
每当Q2出站队列满时将该队列记录放入set中，待遍历所有可能之后一次性输出所有结果
*/

set<string> ans;

//S表示火车站，Q1是即将入站队列，Q2是即将出站队列
void inandOut(stack<int> S, queue<int> Q1, queue<int> Q2){
    string str;
    queue<int> Q1temp = Q1, Q2temp = Q2;
    stack<int> Stemp = S;
    if(Q1.size() > 1){
        S.push(Q1.front());
        Q1.pop();
        Q1temp = Q1;
        Q2temp = Q2;
        Stemp = S;
        while(!S.empty()){
            Q2.push(S.top());
            S.pop();
            inandOut(S, Q1, Q2);
        }
        inandOut(Stemp, Q1temp, Q2temp);
    }
    else if(Q1.size() == 1){
        S.push(Q1.front());
        Q1.pop();
        Q2.push(S.top());
        S.pop();

        while(!S.empty()){
            Q2.push(S.top());
            S.pop();
        }
        str.push_back(Q2.front() + '0');
        Q2.pop();
        while(!Q2.empty()){
            str.push_back(' ');
            str.push_back(Q2.front() + '0');
            Q2.pop();
        }
        ans.insert(str);
        str.clear();
    }
}

int main(void){
    int n;
    int temp;
    queue<int> Q1, Q2;
    stack<int> S;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        Q1.push(temp);
    }
    inandOut(S, Q1, Q2);
    for(set<string>::iterator it = ans.begin(); it != ans.end(); it++){
        cout << (*it) << endl;
    }
    return 0;
}