#include <iostream>
#include <string>
#include <array>
using namespace std;
//读一个两位数。读一个三位数，读一个六位数，读一个大于六位的六位数，挺离谱的

array<string, 10> num1 = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
array<string, 10> num2 = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
array<string, 10> num3 = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string readTwobit(int n){
    if(n < 10){
        return num1[n];
    }
    else if(n >= 10 && n <= 19){
        return num2[n%10];
    }
    else if(n % 10 == 0){
        return num3[n/10];
    }
    else {
        return num3[n/10] + ' ' + num1[n%10];
    }
}

string readThreebit(int n){
    int n1, n2, n3;
    string ans;
    n1 = n % 10;
    n2 = n/10 % 10;
    n3 = n / 100;
    if(n3 != 0){
        ans = num1[n3] + " hundred";
        if(n2*10 + n1 != 0){
            ans = ans + " and " + readTwobit(n2*10 + n1);
        }
    }
    else{
        ans = readTwobit(n2*10 + n1);
    }
    return ans;
}
string readSixbit(int n){
    int thou;
    thou = n/1000 % 1000;
    string ans;
    ans = readThreebit(thou) + " thousand";
    if(n % 1000 != 0){
        // if(n % 1000 > 100 || n % 1000 < 10){
        //     ans = ans + ' ' + readThreebit(n % 1000);
        // }
        // else{
        //     ans = ans + " and " + readThreebit(n % 1000);
        // }
        ans = ans + ' ' + readThreebit(n % 1000);
    }
    return ans;
}
//读一个小于或等于2000000的数
string read(int n){
    int million, thou;
    thou = n/1000 % 1000;
    million = n / 1000000;
    string ans;
    if(n < 1000){
        ans = readThreebit(n);
    }
    else if( n < 1000000){
        ans = readThreebit(thou) + " thousand";
        if(n % 1000 != 0){
            if(n % 1000 >= 100){
                ans = ans + ' ' + readThreebit(n % 1000);
            }
            else{
                ans = ans + " and " + readThreebit(n % 1000);
            }
            // ans = ans + ' ' + readThreebit(n % 1000);
        }

    }
    else{
        ans = readTwobit(million) + " million";
        if(n % 1000000 != 0){
            ans = ans + ' ' + readSixbit(n % 1000000);
        }
    }
    return ans;
}

int main() {

    long n;
    scanf("%lu", &n);

    cout << read(n) << endl;
    return 0;
}
// 64 位输出请用 printf("%lld")