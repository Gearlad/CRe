#include <stdio.h>
 
int numBlocks(const int *ptrArray[]) {
    int i = 0;
    int count = 0;
    while(1) {
        if(ptrArray[i] == NULL) {
            count++;
            if(ptrArray[i+1] == NULL) {
                break;
            }
        }
        i++;
    }
    return count;
}
 
int sizeArr(const int *ptrArray[]) {
    int i;
    for(i = 1; !(ptrArray[i] == NULL && ptrArray[i-1] == NULL); i++) {}
    return i;
}
 
void sumOfIntegers(const int *ptrArray[], int answer[], int *numberOfBlocks) {
    *numberOfBlocks = numBlocks(ptrArray);
    int len = sizeArr(ptrArray);
 
    int startInd = 0;
    int sum = 0;
    int block = 0;
 
    for(int i = 0; i < len; i++) {
        if(ptrArray[i] == NULL) {
            answer[block] = sum;
            startInd = i+1;
            block++;
            sum = 0;
        } else {
            int duplicate = 0;
            for(int j = startInd; j < i; j++) {
                if(ptrArray[i] == ptrArray[j])
                    duplicate = 1;
            }
            if(!duplicate) {
                sum += *ptrArray[i];
            }
        }
    }
}
