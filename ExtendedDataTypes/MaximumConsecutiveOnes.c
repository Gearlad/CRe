#include <stdio.h>
 
main() {
 
    int input;
 
    while(scanf("%d", &input) != EOF) {
        int placeHolder = 1;
        int power = 0;
        int max = 0;
        int prev = 1;
 
        while(1) {
            if(placeHolder < 0) {
                placeHolder = prev;
                break;
            }
            else if(placeHolder > input) {
                placeHolder /= 2;
                break;
            }
            placeHolder *= 2;
            power++;
            if(power > 1) {
                prev *= 2;
                //printf("placeholder: %d\n", prev);
            }
        }
 
        int consec = 0;
 
        //printf("power: %d\n", power);
        for(int i = power-1; i >= 0; i--) {
            if(input == 0) break;
 
            if(input >= placeHolder) {
                input -= placeHolder;
                consec++;
                if(consec > max) max = consec;
                //printf("1");
            } else {
                consec = 0;
                //printf("0");
            }
            placeHolder /= 2;
        }
 
        printf("%d\n", max);
 
    }
 
}
