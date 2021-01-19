#include <stdio.h>
 
main() {
    int k;
    scanf("%d", &k);
 
    int tempdigits = 0;
    int currentdigit;
    int count = 0;
 
    int lessThanOne = 0;
 
    while(scanf("%d", ¤tdigit) != EOF) {
        tempdigits += currentdigit;
 
        //printf("%d\n", tempdigits);
 
        if(k > tempdigits && count == 0) {
            lessThanOne = 1;
        }
 
        if(k > tempdigits && count > 0) {
            lessThanOne = 0;
            printf("0\n");
        }
 
        if(k <= tempdigits) {
            for(int i = 9; i >= 1; i--) {
 
                /*printf("current: %d, temp: %d, i: %d\n", currentdigit, tempdigits, i);
                printf("temp digits: %d\n", tempdigits);
                printf("%d, %d\n", i, k);*/
                if(k * i <= tempdigits) {
                    tempdigits -= (k*i);
                    printf("%d\n", i);
                    break;
                }
            }
        }
        tempdigits *= 10;
        count++;
    }
 
    if(count == 1 && lessThanOne == 1) {
        printf("0");
    }
 
    //subtasks
    //divide by 1, even number
    //divide by 2, even number
    return 0;
}
