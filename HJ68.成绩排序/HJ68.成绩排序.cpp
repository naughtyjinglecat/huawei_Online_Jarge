#include <iostream>
#include <random>
#include <string>
#include <algorithm>
using namespace std;

typedef struct classmate{
    string name;
    int credit;
    int index;
    bool friend operator <(classmate a, classmate b){
        if(a.credit < b.credit){
            return true;
        }
        else if(a.credit == b.credit){
            return a.index < b.index;
        }
        else{
            return false;
        }
    }
}classmate;

bool cmp(classmate a, classmate b){
        if(a.credit > b.credit){
            return true;
        }
        else if(a.credit == b.credit){
            return a.index < b.index;
        }
        else{
            return false;
        }
}

int main() {
    int n;
    int tag;
    classmate *classmates;
    cin >> n >> tag;
    classmates = new classmate[n];
    for(int i = 0; i < n; i++){
        classmates[i].index = i;
        cin >> classmates[i].name >> classmates[i].credit;
    }
    if(tag == 1){
        sort(classmates, classmates + n);
    }
    else{
        sort(classmates, classmates + n, cmp);
    }
    for(int i = 0; i < n; i++){
        cout << classmates[i].name << ' ' << classmates[i].credit << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")