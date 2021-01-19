#include <stdio.h>
 
int N, M;
int aspects[7] = {0, 0, 0, 0, 0, 0, 0};
//1234567
int essences[2] = {0, 0};
 
main() {
    scanf("%d%d", &N, &M);
 
    //N appears in M
 
    for(int i = 0; i < 6; i++) {
        aspects[6-i] = M % 10;
        M /= 10;
    }
    aspects[0] = M;
 
    essences[1] = N % 10;
    N /= 10;
    essences[0] = N;
 
    unsigned totalMatches = 0;
    for(unsigned i = 0; i < 6; i++) {
        //printf("%d, %d\n", aspects[i], essences[match]);
        if(aspects[i] == essences[0] && aspects[i+1] == essences[1]) {
            totalMatches++;
        }
    }
    printf("%d", totalMatches);
 
