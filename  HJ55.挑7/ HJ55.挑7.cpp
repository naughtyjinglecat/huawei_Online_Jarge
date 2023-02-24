#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int n;
    int temp;
    cin >> n;
    for(int i = 7; i <= n; i++){
        if(i % 7 == 0){
            count++;
            continue;
        }
        temp = i;
        while(temp != 0){
            if(temp % 10 == 7){
                count++;
                break;
            }
            else{
                temp /= 10;
            }
        }
    }
    cout << count << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")