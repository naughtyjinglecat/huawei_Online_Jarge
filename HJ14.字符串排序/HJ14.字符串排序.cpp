#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    map<string, int> sentences;
    string temp;
    map<string, int>::iterator it2;
    int count;
    cin >> count;
    for(int i = 0; i < count; i++){
        cin >> temp;
        if(sentences.find(temp) == sentences.end()){
            sentences[temp] = 1;
        }
        else{
            sentences[temp]++;
        }
    }
    for(map<string, int>::iterator it = sentences.begin(); it != sentences.end(); it++){
        for(int i = 0; i < it->second; i++){
            cout << it->first << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")