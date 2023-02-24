#include <iostream>
#include <string>
#include <array>
#include <map>
using namespace std;


bool check(string commands, string command){
    int j = 0;
    int count1 = 0, count2 = 0;
    for(int i = 0; i < (int)commands.size(); i++){
        if(commands[i] == ' '){
            count1++;
        }
    }
    for(int i = 0; i < (int)command.size(); i++){
        if(command[i] == ' '){
            count2++;
        }
    }
    if(count1 != count2){
        return false;
    }
    for(int i = 0; i < command.size(); i++){
        if(command[i] != ' '){
            if(command[i] == commands[j]){
                j++;
            }
            else{
                return false;
            }
        }
        else{
            for(; j < commands.size(); j++){
                if(commands[j] == ' '){
                    j++;
                    break;
                }
            }
            if(commands[j] == '\0'){
                return false;
            }
        }
    }
    return true;
}

string quickPatch(string command){
    array<string, 6> commands = {"reset", "reset board", "board add", "board delete", "reboot backplane", "backplane abort"}, excu = {"reset what", "board fault", "where to add", "no board at all", "impossible", "install first"};
    string ans = "unknown command";
    int count = 0;
    int pos = -1;
    for(int i = 0; i < 6; i++){
        if(command == commands[i]){
            return excu[i];
        }
        if(check(commands[i], command)){
            count++;
            if(pos == -1){
                pos = i;
            }
            if(count == 2){
                break;
            }
        }
    }
    if(count == 1){
        ans = excu[pos];
    }
    return ans;
}

int main() {
    string command;
    while(getline(cin, command)){
        cout << quickPatch(command) << endl;
    }
    return 0;
}
// 64 位输出请用 printf("%lld")