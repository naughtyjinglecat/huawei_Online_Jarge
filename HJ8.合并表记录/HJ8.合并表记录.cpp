#include <cstdio>
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;


int main() {
    map<int, int> vallist;
    int n;
    int indexTemp, valueTemp;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &indexTemp, &valueTemp);
        if(vallist.find(indexTemp) == vallist.end()){
            vallist[indexTemp] = valueTemp;
        }
        else {
            vallist[indexTemp] += valueTemp;
        }
    }
    for(map<int, int>::iterator it = vallist.begin(); it != vallist.end(); it++){
        printf("%d %d\n", it->first, it->second);
    }
    return 0;
}
// 64 位输出请用 printf("%lld")