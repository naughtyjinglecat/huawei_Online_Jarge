#include <iostream>
#include <string>
using namespace std;

char secret(char a){
    if(a >= '0' && a <= '9'){
        return (char)((a - '0' + 11) % 10 + '0');
    }
    else if(a >= 'A' && a <= 'Z'){
        return (a - 'A' + 1) % 26 + 'a';
    }
    else{
        return (a - 'a' + 1) % 26 + 'A';
    }
}
char release(char a){
    if(a >= '0' && a <= '9'){
        return (char)((a - '0' - 1 + 10) % 10 + '0');
    }
    else if(a >= 'A' && a <= 'Z'){
        return (a - 'A' + 25) % 26 + 'a';
    }
    else{
        return (a - 'a' + 25) % 26 + 'A';
    }
}


int main() {
    string password1, password2;
    cin >> password1 >> password2;
    for(int i = 0; i < (int)password1.size(); i++){
        cout << secret(password1[i]);
    }
    cout << endl;
    for(int i = 0; i < (int)password2.size(); i++){
        cout << release(password2[i]);
    }
    cout << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")