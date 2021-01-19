#include <stdio.h>
 
int digitCounter(int a);
int firstDig(int a);
 
main() {
    int num;
    scanf("%d", &num);
 
    int finalMax = digitCounter(num);
    int finalDigit = finalMax > 1 ? num % 10 : num;
    int currentMax = finalMax;
    int firstDigit;
 
    int prevNum;
 
    while(scanf("%d", &num) != EOF) {
        firstDigit = firstDig(num);
        int digitCount = digitCounter(num);
        #ifdef DEBUG
            printf("num: %d\n", num);
            printf("first digit: %d\n", firstDigit);
            printf("digit count: %d\n", digitCount);
        #endif
 
        if(firstDigit == finalDigit) {  // connected to prev sequence
            #ifdef DEBUG
                printf("first digit and final digit are equal\n");
            #endif
            currentMax += digitCount;
            if(currentMax > finalMax) finalMax = currentMax;
        }
 
        else {  // not connected
            #ifdef DEBUG
                printf("first digit and final digit are NOT equal\n");
            #endif
            if(currentMax > finalMax) finalMax = currentMax;
            currentMax = digitCount;
        }
 
        finalDigit = digitCount > 1 ? num % 10 : num;
        #ifdef DEBUG
            printf("final digit: %d\n", finalDigit);
            puts("");
        #endif
    }
 
    printf("%d\n", finalMax);
 
    return 0;
}
 
int digitCounter(int a) {
    int c = 1;
    while(a >= 10) {
        a /= 10;
        c++;
    }
    return c;
}
 
int firstDig(int a) {
    while(a >= 10) {
        a /= 10;
    }
    return a;
}
