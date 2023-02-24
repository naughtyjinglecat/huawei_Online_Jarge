#include <iostream>
#include <string>
using namespace std;

void lower(string &str){
    for(int i = 0; i < (int)str.size(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

bool isPatch(string str1, string str2){
    int i = 0, j = 0;
    string substr1, substr2;
    lower(str1);
    lower(str2);
    while(i < (int)str1.size() && j < (int)str2.size()){
        if(str1[i] == '?'){
            if(((str2[j] > 'z' || str2[j] < 'a') && (str2[j] > '9' || str2[j] < '0'))){
                return false;
            }
            i++;
            j++;
        }
        else if(str1[i] == '*'){
            for(; i < (int)str1.size(); i++){
                if(str1[i] != '*'){
                    break;
                }
            }
            for(; j < (int)str2.size(); j++){
                if(str1[i] == str2[j] || str1[i] == '?'){
                    substr1 = str1.substr(i, str1.size() - i);
                    substr2 = str2.substr(j, str2.size() - j);
                    if(isPatch(substr1, substr2)){
                        return true;
                    }
                }
                if((str2[j] > 'z' || str2[j] < 'a') && (str2[j] > '9' || str2[j] < '0')){
                    return false;
                }
            }

        }
        else if(str1[i] == str2[j] || str1[i] == '?'){
            i++;
            j++;
        }
        else{
            return false;
        }

        
    }
    if(i == (int)str1.size() && j == (int)str2.size()){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if(isPatch(str1, str2)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")