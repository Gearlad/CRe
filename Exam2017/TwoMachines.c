#include <stdio.h>
#include <stdbool.h>
 
main() {
 
    int ANext = 0, BNext = 0;
 
    int arrival, ATime, BTime;
 
    bool first = true;
 
    while(scanf("%d%d%d", &arrival, &ATime, &BTime) != EOF) {
        //printf("START OF LOOP -----\n");
        //printf("%d, %d, %d\n", arrival, ATime, BTime);
 
 
        if(first) {
            first = false;
            ANext = arrival;
        }
 
        //process it going through A
        //it will finish going through A when A is next ready
 
        if(arrival > ANext) {
            ANext += (arrival - ANext);
        }
        ANext += ATime;
 
        if(BNext < ANext) {
            BNext += (ANext - BNext) + BTime;
        } else if(BNext >= ANext) {
            BNext += BTime;
        }
 
        printf("%d\n", BNext);
    }
 
    return 0;
}
