#include <climits>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <array>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<char> &tobeDeleted, char t){
    for(int i = 0; i < tobeDeleted.size(); i++){
        if(tobeDeleted[i] == t){
            return i;
        }
    }
    return tobeDeleted.size();
}

int main() {
    array<int, 128> hashtable;
    char temp;
    string word;
    vector<char> tobeDeleted;
    int minCount = 21;
    cin >> word;
    fill(hashtable.begin(), hashtable.end(), 0);
    for(int i = 0; i < word.size(); i++){
        hashtable[word[i]]++;
    }
    for(char i = 'a'; i <= 'z'; i++){
        if(hashtable[i] > 0 && hashtable[i] < minCount){
            minCount = hashtable[i];
            tobeDeleted.clear();
            tobeDeleted.push_back(i);
        }
        else if(hashtable[i] == minCount){
            tobeDeleted.push_back(i);
        }
    }
    for(int i = 0; i < word.size(); i++){
        if(find(tobeDeleted ,word[i]) == tobeDeleted.size()){
            printf("%c", word[i]);
        }
    }
    printf("\n");
    return 0;
}
// 64 位输出请用 printf("%lld")