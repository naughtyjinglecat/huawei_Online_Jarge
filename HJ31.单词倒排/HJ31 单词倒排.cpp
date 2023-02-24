#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isLetter(char a){
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z');
}

int main() {
    string sentence;
    string temp;
    stack<string> ouputBox;
    char tempc = getchar();
    while(tempc != '\n'){
        sentence.push_back(tempc);
        tempc = getchar();
    }
    
    for(int i = 0; i < sentence.size(); i++){
        if(isLetter(sentence[i])){
            temp.push_back(sentence[i]);
        }
        else{
            if(temp.size() != 0){
                ouputBox.push(temp);
            }
            temp.clear();
        }
    }
    if(temp.size() != 0){
        ouputBox.push(temp);
    }
    if(!ouputBox.empty()){
        cout << ouputBox.top();
        ouputBox.pop();
    }
    while(!ouputBox.empty()){
        cout << ' ' << ouputBox.top();
        ouputBox.pop();
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")