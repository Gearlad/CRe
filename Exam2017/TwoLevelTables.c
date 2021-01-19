#include <stdlib.h>
#include "constructTable.h"
 
int ***constructTable(int A[], int B[]) {
    int n = 0;
    while(A[n++] != 0);
    int ***ptr = (int ***) malloc(sizeof(int**) * (n+1));
    for(int i = 0, bpos = 0; i < n; i++) {
        ptr[i] = (int **)malloc(sizeof(int*) * (A[i]+1));
        for(int j = 0; j < A[i]; j++) {
            ptr[i][j] = &B[bpos];
            while(B[bpos++] != 0);
        }
        ptr[i][A[i]] = NULL;
    }
    return ptr;
}
