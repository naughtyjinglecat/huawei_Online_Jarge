#include <cstdio>
#include <iostream>
#include <memory>
using namespace std;

typedef struct rubbit{
    int ageInOne;
    int ageInTwo;
    int ageInThree;
    rubbit(){
        ageInOne = 0;
        ageInTwo = 0;
        ageInThree = 0;
    }
}rubbit;
int main() {
    rubbit *rubbits = new rubbit[3];
    rubbit firstTemp;
    rubbit secondTemp;
    rubbits[2].ageInOne = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        firstTemp = rubbits[1];
        secondTemp = rubbits[2];
        rubbits[1] = secondTemp;
        rubbits[0] = firstTemp;
        rubbits[2].ageInOne = rubbits[1].ageInTwo + rubbits[1].ageInThree;
        rubbits[2].ageInTwo = rubbits[1].ageInOne;
        rubbits[2].ageInThree += rubbits[1].ageInTwo;
    }
    printf("%d\n", rubbits[2].ageInOne + rubbits[2].ageInTwo + rubbits[2].ageInThree);
    return 0;
}
// 64 位输出请用 printf("%lld")