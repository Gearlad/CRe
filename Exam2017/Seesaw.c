#include <stdio.h>
 
void printSequence(int arr[], int size, int balanceIndex);
void swap(int *val1, int *val2);
 
main() {
    int numWeights;
    scanf("%d", &numWeights);
 
    int weights[numWeights];
 
    for(int i = 0; i < numWeights; i++) {
        scanf("%d", &weights[i]);
    }
 
#ifdef DEBUG
    printSequence(weights, numWeights, -1);
#endif
 
    int balanceIndex = -1;
    int leftSide, rightSide;
    int multiplier;
    int swapIndex = 0;
 
    while(balanceIndex == -1) {
        for(int i = 0; i < numWeights; i++) {
            multiplier = 1;
            leftSide = 0;
            for(int j = i-1; j >= 0; j--) {
                leftSide += weights[j] * multiplier;
                multiplier++;
            }
 
            multiplier = 1;
            rightSide = 0;
            for(int j = i + 1; j < numWeights; j++) {
                rightSide += weights[j] * multiplier;
                multiplier++;
            }
 
            if(rightSide == leftSide) {
                balanceIndex = i;
                break;
            }
        }
        if(balanceIndex == -1) {
            swap(&weights[swapIndex],
            &weights[numWeights - swapIndex - 1]);
            swapIndex++;
        }
    }
 
    printSequence(weights, numWeights, balanceIndex);
 
    return 0;
 
}
 
void printSequence(int arr[], int size, int balanceIndex) {
    for(int i = 0; i < size-1; i++) {
        if(i == balanceIndex) printf("v ");
        else printf("%d ", arr[i]);
    }
    printf("%d", arr[size-1]);
}
 
void swap(int *val1, int *val2) {
    int temp;
    temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}
