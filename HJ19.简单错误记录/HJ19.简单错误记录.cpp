#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct record{
    string name;
    int index;
    int count;
    bool friend operator == (record a, record b){
        return a.index == b.index && a.name == b.name;
    }
    record(){
        count = 1;
    }
}record;

int find(vector<record> records, record n){
    for(int i = 0; i < (int)records.size(); i++){
        if(records[i] == n){
            return i;
        }
    }
    return (int)records.size();
}

int main() {
    string curStr;
    int curIndex;
    record recordTemp;
    int i;
    int num;
    vector<record> records;
    while(cin >> curStr >> curIndex){
        for(i = (int)curStr.size()-1; i >= 0 && i > (int)curStr.size()-16 && curStr[i-1] != '\\'; i--){
            
        }
        recordTemp.name = curStr.substr(i, (int)curStr.size() - i + 1);
        recordTemp.index = curIndex;
        num = find(records, recordTemp);
        if(num == (int)records.size()){
            records.push_back(recordTemp);
        }
        else{
            records[num].count++;
        }
    }
    for(int i = (int)records.size()-8; i < (int)records.size(); i++){
        if(i < 0){
            continue;
        }
        cout << records[i].name << ' ' << records[i].index << ' ' << records[i].count << endl;
    }


    return 0;
}
// 64 位输出请用 printf("%lld")