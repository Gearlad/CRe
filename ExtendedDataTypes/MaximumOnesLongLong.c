#define MAXVAL 9223372036854775807
#define POWER62 4611686018427387904
 
#include <stdio.h>
 
int main() {
    long long int input;
 
    while(scanf("%lld", &input) != EOF) {
 
 
        long long int placeHolder = POWER62;
        int numOnes = 0;
 
 
        for(int i = 63; i >= 1 && placeHolder >= 1; i--) {
            if(input >= placeHolder) {
                input -= placeHolder;
                numOnes++;
            }
            placeHolder /= 2;
        }
 
        printf("%d\n", numOnes);
 
 
    }
    return 0;
}
