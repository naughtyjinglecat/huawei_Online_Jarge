#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

/*总之就是没做出来*/

int getN(char *str){
    int ans = -1;
    int i = 0;
    if(str[i] >= '0' && str[i] <= '9'){
        ans = 0;
    }
    while(str[i] >= '0' && str[i] <= '9'){
        ans = ans *10 + str[i] - '0';
        i++;
    }
    return ans;
}

void getnum(char *str, int &ip1, int &ip2, int &ip3, int &ip4, int &mask1, int &mask2, int &mask3, int &mask4){
    char temp = str[0];
    int i = 0;
    ip1 = getN(str);
    while(str[i] != '.'){
        i++;
    }
    i++;
    ip2 = getN(str+i);
    while(str[i] != '.'){
        i++;
    }
    i++;
    ip3 = getN(str+i);
    while(str[i] != '.'){
        i++;
    }
    i++;
    ip4 = getN(str+i);
    while(str[i] != '~'){
        i++;
    }
    i++;
    mask1 = getN(str+i);
    while(str[i] != '.'){
        i++;
    }
    i++;
    mask2 = getN(str+i);
    while(str[i] != '.'){
        i++;
    }
    i++;
    mask3 = getN(str+i);
    while(str[i] != '.'){
        i++;
    }
    i++;
    mask4 = getN(str+i);
}

string HTB(int n){
    string str;
    while(n != 0){
        if(n % 2 == 0){
            str.push_back('0');
        }
        else{
            str.push_back('1');
        }
        n /= 2;
    }
    reverse(str.begin(), str.end());
    if(str.size() == 0){
        str.push_back('0');
    }
    return str;
}

bool checkmask(int mask1, int mask2, int mask3, int mask4){
    int i = 0;
    string str = HTB(mask1) + HTB(mask2) + HTB(mask3) + HTB(mask4);
    if(mask1 > 255 || mask2 > 255 || mask3 > 255 || mask4 > 255){
        return false;
    }
    for(i = 0; i < str.size(); i++){
        if(str[i] == '1'){
            continue;
        }
        else{
            break;
        }
    }
    if(str == "0000" || str == "11111111111111111111111111111111"){
        return false;
    }
    for(; i < str.size(); i++){
        if(str[i] == '0'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(void) {
    int ip1 = -1, ip2 = -1, ip3 = -1, ip4 = -1;
    int mask1 = -1, mask2 = -1, mask3 = -1, mask4 = -1;
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, eCount = 0;
    int errorIp = 0, errormask = 0;
    int privateIp = 0;
    char str[50];
    while (scanf("%s", str) != EOF){
        getnum(str, ip1, ip2, ip3, ip4, mask1, mask2, mask3, mask4);
        if((ip1 == 0 || ip1 == 127) && (ip1 != -1 && ip2 != -1 && ip3 != -1 && ip4 != -1 && mask1 != -1 && mask2 != -1 && mask3 != -1 && mask4 != -1)){
            continue;
        }

        if(!checkmask(mask1, mask2, mask3, mask4)){
            errorIp++;
            continue;
        }
        if( ip1 == -1 || ip2 == -1 || ip3 == -1 || ip4 == -1 || mask1 == -1 || mask2 == -1 || mask3 == -1 || mask4 == -1 ){
            errorIp++;
            continue;
        }
        if(ip1 > 255 || ip2 > 255 || ip3 > 255 || ip4 > 255){
            errorIp++;
            continue;
        }
        if(ip1 >= 1 && ip1 <= 126 && ip2 >= 0 && ip2 <= 255 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            aCount++;
        }
        else if(ip1 >= 128 && ip1 <= 191 && ip2 >= 0 && ip2 <= 255 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            bCount++;
        }
        else if(ip1 >= 192 && ip1 <= 223 && ip2 >= 0 && ip2 <= 255 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            cCount++;
        }
        else if(ip1 >= 224 && ip1 <= 239 && ip2 >= 0 && ip2 <= 255 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            dCount++;
        }
        else if(ip1 >= 240 && ip1 <= 255 && ip2 >= 0 && ip2 <= 255 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            eCount++;
        }
        if(ip1 >= 10 && ip1 <= 10 && ip2 >= 0 && ip2 <= 255 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            privateIp++;
        }
        if(ip1 == 172 && ip2 >= 16 && ip2 <= 31 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            privateIp++;
        }
        if(ip1 == 192 && ip2 == 168 && ip3 >= 0 && ip3 <= 255 && ip4 >= 0 && ip4 <= 255){
            privateIp++;
        }
    }
    printf("%d %d %d %d %d %d %d\n", aCount, bCount, cCount, dCount, eCount, errorIp, privateIp);
    return 0;
}
// 64 位输出请用 printf("%lld")


