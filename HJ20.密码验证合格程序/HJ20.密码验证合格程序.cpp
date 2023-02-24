#include <iostream>
#include <iterator>
#include <string>
using namespace std;

bool checkLength(string password){
    if(password.size() > 8){
        return true;
    }
    else{
        return false;
    }
}
bool checkSign(string password){
    bool signUp = false, signDown = false, signNum = false, signOther = false;
    int count = 0;
    for(int i = 0; i < password.size(); i++){
        if(password[i] >= '0' && password[i] <= '9'){
            signNum = true;
        }
        else if(password[i] >= 'a' && password[i] <= 'z'){
            signDown = true;
        }
        else if(password[i] >= 'A' && password[i] <= 'Z'){
            signUp = true;
        }
        else if(password[i] != ' '){
            signOther = true;
        }
    }
    if(signOther){
        count++;
    }
    if(signUp){
        count++;
    }
    if(signDown){
        count++;
    }
    if(signNum){
        count++;
    }
    if(count >= 3){
        return true;
    }
    else{
        return false;
    }
}
bool checksubStr(string password){
    for(int i = 0; i < (int)password.size() - 3; i++){
        for(int j = i + 1; j < (int)password.size() - 2; j++){
            if(password[i] == password[j] && password[i+1] == password[j+1] && password[i+2] == password[j+2]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    string password;
    while(getline(cin, password)){
        if(checkLength(password) && checkSign(password) && checksubStr(password)){
            cout << "OK" << endl;
        }
        else{
            cout << "NG" << endl;
        }
    }
    return 0;
}
// 64 位输出请用 printf("%lld")