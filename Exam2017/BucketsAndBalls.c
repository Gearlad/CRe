#include <stdio.h>
 
main() {
    int capacityA, capacityB, rule;
 
    scanf("%d%d%d", &capacityA, &capacityB, &rule);
 
    int weight;
    while(scanf("%d", &weight) != EOF) {
        if(rule == 0) {
            //first fit
            if(capacityA >= weight) {
                capacityA -= weight;
            } else if(capacityB >= weight) {
                capacityB -= weight;
            }
        }
 
        else if(rule == 1) {
            //best fit (least remaining capacity)
            if(capacityA >= weight && capacityB >= weight) {
                if(capacityA <= capacityB) capacityA -= weight;
                else if(capacityB < capacityA) capacityB -= weight;
            } else if(capacityA >= weight && capacityB < weight) {
                capacityA -= weight;
            } else if(capacityB >= weight && capacityA < weight) {
                capacityB -= weight;
            }
        }
        printf("%d %d\n", capacityA, capacityB);
    }
 
    return 0;
 
}
