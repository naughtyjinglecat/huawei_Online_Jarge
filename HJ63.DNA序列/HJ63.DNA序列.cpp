#include <iostream>
#include <string>
using namespace std;

string maxGCradio(string DNA, int n){
    int curGCcount = 0, maxGCcount = 0;
    int pos = 0;
    string ans;
    if(n >= (int)DNA.size()){
        return DNA;
    }
    else{
        for(int i = 0; i < n; i++){
            if(DNA[i] == 'C' || DNA[i] == 'G'){
                curGCcount++;
            }
        }
        maxGCcount = curGCcount;
        for(int i = 1; i < (int)DNA.size() - n + 1; i++){
            if(DNA[i - 1] == 'G' || DNA[i - 1] == 'C'){
                curGCcount--;
            }
            if(DNA[i + n - 1] == 'G' || DNA[i + n - 1] == 'C'){
                curGCcount++;
            }
            pos = (maxGCcount >= curGCcount) ? pos : i;
            maxGCcount = (maxGCcount >= curGCcount) ? maxGCcount : curGCcount;
        }
        ans = DNA.substr(pos, n);
    }
    return ans;

}

int main() {
    int n;
    string DNA;
    cin >> DNA >> n;
    cout << maxGCradio(DNA, n);
    return  0;
}
// 64 位输出请用 printf("%lld")