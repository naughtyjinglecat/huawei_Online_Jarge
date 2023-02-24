#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;
    getline(cin, sentence);
    int enCount = 0, spaceCount = 0, numCount = 0;
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] >= '0' && sentence[i] <= '9'){
            numCount++;
        }
        else if((sentence[i] >= 'a' && sentence[i] <= 'z') || (sentence[i] >= 'A' && sentence[i] <= 'Z')){
            enCount++;
        }
        else if(sentence[i] == ' '){
            spaceCount++;
        }
    }
    cout << enCount << endl << spaceCount << endl << numCount << endl << sentence.size()-enCount-numCount-spaceCount << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")    int a, b;