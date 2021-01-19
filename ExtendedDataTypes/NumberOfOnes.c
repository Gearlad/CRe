#include <stdio.h>
 
main() {
    int input;
 
    while(scanf("%d", &input) != EOF) {
        int placeHolder = 1;
        int power = 0;
 
        int numOnes = 0;
 
        while(1) {
            if(placeHolder < 0) {
                numOnes = 31;
                break;
            }
            if(placeHolder > input) {
                placeHolder /= 2;
                break;
            }
            placeHolder *= 2;
            power++;
        }
 
        //printf("power: %d\n", power);
        if(numOnes == 0) {
            for(int i = power-1; i >= 0; i--) {
                if(input == 0) break;
 
                if(input >= placeHolder) {
                    input -= placeHolder;
                    numOnes++;
                    //printf("1");
                } //else printf("0");
                placeHolder /= 2;
            }
        }
 
        printf("%d\n", numOnes);
 
    }
 
}
