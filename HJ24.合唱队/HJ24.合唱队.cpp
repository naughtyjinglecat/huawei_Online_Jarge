#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//线求递增序列，若是当前人不入队，则当前最大递增序列就会左侧最大递增序列，
//如实入队，则找到左侧第一个比当前人矮的人在其右侧入队
//递减序列同理


int max(int a, int b){
    return (a > b) ? a : b;
}

typedef struct person{
    int height, left, right;
    person(){
        height = 0;
        left = 0;
        right = 0;
    }
}person;

int main() {
    int n;
    int temp = 1;
    cin >> n;
    person *persons = new person[n];
    persons[0].left = 1;
    persons[n-1].right = 1;
    for(int i = 0; i < n; i++){
        cin >> persons[i].height;
    }
    for(int i = 1; i < n; i++){
        temp = 0;
        for(int j = 0; j < i; j++){
            if(persons[i].height > persons[j].height){
                temp = persons[j].left > temp ? persons[j].left : temp;
            }
        }
        persons[i].left = temp + 1;
    }
    for(int i = n - 2; i >= 0; i--){
        temp = 0;
        for(int j = n - 1; j > i; j--){
            if(persons[i].height > persons[j].height){
                temp = persons[j].right > temp ? persons[j].right : temp;
            }
        }
        persons[i].right = temp + 1;
    }
    temp = 0;
    for(int i = 0; i < n; i++){
        temp = (persons[i].left + persons[i].right - 1 > temp) ? persons[i].left + persons[i].right - 1 : temp;
    }
    cout << n - temp;
    return 0;
}
// 64 位输出请用 printf("%lld")