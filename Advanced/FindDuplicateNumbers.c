#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXN 100000
 
int main(void) {
    int seen[MAXN];
    memset(seen, 0, MAXN);
 
    int N;
    scanf("%d", &N);
 
    int curr;
    for(int i = 0; i < N; i++) {
        scanf("%d", &curr);
        if(seen[curr] > 0) {
            printf("%d\n", curr);
            break;
        }
        seen[curr]++;
    }
    return 0;
}
