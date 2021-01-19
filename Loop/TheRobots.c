#include <stdio.h>
#include <stdlib.h>
 
void boundaries(int* X1, int* Y1, int* X2, int* Y2, int M, int N);
 
main() {
    int M, N, X1, Y1, E1, N1, F1, X2, Y2, E2, N2, F2;
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &M, &N, &X1, &Y1, &E1, &N1,
    &F1, &X2, &Y2, &E2, &N2, &F2);
 
    int N1Copy = N1;
    int E1Copy = E1;
 
    int E2Copy = E2;
    int N2Copy = N2;
 
    int topFuel = F1 > F2 ? F1 : F2;
 
    for(int i = 0; i < topFuel; i++) {
        if(F1 > 0) {
            if(N1Copy > 0) {
                Y1++;
                N1Copy--;
                if(N1Copy == 0) E1Copy = E1;
            }
            else if(E1Copy > 0) {
                X1++;
                E1Copy--;
                if(E1Copy == 0) N1Copy = N1;
            }
            F1--;
        }
 
        if(F2 > 0) {
            if(E2Copy > 0) {
                X2++;
                E2Copy--;
                if(E2Copy == 0) N2Copy = N2;
            } else if(N2Copy > 0) {
                Y2++;
                N2Copy--;
                if(N2Copy == 0) E2Copy = E2;
            }
            F2--;
        }
 
        boundaries(&X1, &Y1, &X2, &Y2, M, N);
 
        if(X1 == X2 && Y1 == Y2) {
            printf("robots explode at time %d", (i+1));
            exit(0);
        }
 
        //printf("X1: %d, Y1: %d, X2: %d, Y2: %d\n", X1, Y2, X2, Y2);
    }
 
    printf("robots will not explode");
 
 
    return 0;
}
 
void boundaries(int* X1, int* Y1, int* X2, int* Y2, int M, int N) {
    if(*X1 >= M) *X1 = 0;
    if(*X1 < 0) *X1 = M-1;
    if(*Y1 >= N) *Y1 = 0;
    if(*Y1 < 0) *Y1 = N-1;
 
    if(*X2 >= M) *X2 = 0;
    if(*X2 < 0) *X2 = M-1;
    if(*Y2 >= N) *Y2 = 0;
    if(*Y2 < 0) *Y2 = N-1;
}
