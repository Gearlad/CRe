#include <stdio.h>
#define MAXN 100005
int A[MAXN];
int main() {
    int n, i;
    while (scanf("%d", &n) == 1) {
        int numZero = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &A[i]);
 
        for (i = 0; i < n; i++) {
            if(A[i] == 0) {
                numZero++;
            } else {
                printf("%d ", A[i]);
            }
        }
        for(int i = 0; i < numZero; i++) {
            printf("0");
            if(i != numZero-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
