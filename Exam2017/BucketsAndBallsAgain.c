#include <stdbool.h>
 
void place(int bucket[1024], int N, int ball[16384], int M, int method, int result[16384]);
 
 
 
 
void place(int bucket[1024], int N, int ball[16384], int M, int method, int result[16384]) {
 
    int i, j;
 
    //best fit variables
    int largestInd, smallestInd;
    int largest = 0;
 
    switch(method) {
case 0: //first fit
    for(i = 0; i < M; i++) {
        for(j = 0; j < N; j++) {
            if(ball[i] <= bucket[j]) {
                bucket[j] -= ball[i];
                result[i] = j;
                break;
            }
            if(j == N-1) {
                result[i] = -1;
            }
        }
    }
    break;
 
case 1: //best fit
    for(i = 0; i < M; i++) {
        smallestInd = -1;
        for(j = 0; j < N; j++) {
            if(bucket[j] < ball[i]) continue;
 
            if(smallestInd == -1) smallestInd = j;
            else if(bucket[j] < bucket[smallestInd]) smallestInd = j;
        }
 
        result[i] = smallestInd;
        if(smallestInd != -1) bucket[smallestInd] -= ball[i];
    }
 
    break;
case 2: //worst fit
    for(i = 0; i < M; i++) {
        largestInd = -1;
        for(j = 0; j < N; j++) {
            if(bucket[j] < ball[i]) continue;
 
            if(largestInd == -1) largestInd = j;
            else if(bucket[j] >= bucket[largestInd]) largestInd = j;
        }
 
        result[i] = largestInd;
        if(largestInd != -1) bucket[largestInd] -= ball[i];
    }
    break;
 
 
    }
 
 
}
