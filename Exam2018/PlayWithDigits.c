#include <stdio.h>
 
main() {
    int digitCount = 0;
    int num;
    int even;
    int zero = 0;
    int elevenOne = 0;
    int elevenTwo = 0;
 
    while(scanf("%d", &num) != EOF) {
        digitCount++;
        if(num == 0) zero++;
        even = num % 2 == 0;
 
        if(digitCount % 2 == 1) elevenOne += num;
        else elevenTwo += num;
 
        //printf("%d, %d\n", elevenOne, elevenTwo);
 
        //printf("Eleven: %d\n", eleven);
    }
 
    //11 22 33 44 55 66 77 88 99 110 121 132 143 154 165 176 187 198 209
    //220 231 242 253 264 275 286 297 308 319 330 341 352 363 374 385 396
    //407
    int sumDiff = elevenTwo - elevenOne;
    //if(sumDiff < 0) sumDiff = -sumDiff;
    /*if(sumDiff < 0) sumDiff += 11;
    if(sumDiff >= 11) sumDiff -= 11;*/
    //printf("sumDiff: %d\n", sumDiff);
    int eleven = sumDiff % 11 == 0;
    printf("%d\n%d\n%d\n%d", digitCount, even, zero, eleven);
    return 0;
}
