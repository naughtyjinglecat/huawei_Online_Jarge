#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isLetter(char a){
    if((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z')){
        return true;
    }
    return false;
}
void outputWord(int i, string sentence){
    while(isLetter(sentence[i])){
        printf("%c", sentence[i]);
        i++;
    }
}

int main() {
    string sentence;
    stack<int> wordsBegin;
    int i = 0;
    char temp = getchar();
    while(temp != '\n'){
        sentence.push_back(temp);
        if(sentence.size() == 1){
            wordsBegin.push(i);
        }
        else if(!(isLetter(sentence[sentence.size()-2])) && isLetter(sentence[sentence.size()-1])){
            wordsBegin.push(i);
        }
        temp = getchar();
        i++;
    }
    while(!wordsBegin.empty()){
        outputWord(wordsBegin.top(), sentence);
        wordsBegin.pop();
        if(wordsBegin.empty()){
            printf("\n");
        }
        else{
            printf(" ");
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")