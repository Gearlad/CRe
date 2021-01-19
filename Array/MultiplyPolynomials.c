#include <stdio.h>
 
main() {
    int polyOneSize;
    scanf("%d", &polyOneSize);
    int polyOne[polyOneSize];
 
    for(int i = 0; i < polyOneSize; i++) {
        scanf("%d", &polyOne[i]);
    }
 
    int polyTwoSize;
    scanf("%d", &polyTwoSize);
    int polyTwo[polyTwoSize];
 
    for(int i = 0; i < polyTwoSize; i++) {
        scanf("%d", &polyTwo[i]);
    }
 
    int polyMultSize = polyOneSize + polyTwoSize - 1;
    int polyMult[polyMultSize];
 
    //printf("\n");
 
    //just add degrees of two polynomials for product's degree...
 
    for(int i = 0; i < polyMultSize; i++) {
        polyMult[i] = 0;
    }
 
    for(int i = polyOneSize-1; i >= 0; i--) {
        for(int j = polyTwoSize-1; j >= 0; j--) {
            //printf("%d, %d\n", polyOne[i], polyTwo[j]);
            polyMult[i+j] += polyOne[i] * polyTwo[j];
        }
    }
 
    for(int i = 0; i < polyMultSize-1; i++) {
        printf("%d ", polyMult[i]);
    }
    printf("%d", polyMult[polyMultSize-1]);
 
    return 0;
}
