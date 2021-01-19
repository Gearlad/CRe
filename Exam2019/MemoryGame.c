#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXN 100500
 
int deck[MAXN];
int mem[128];
 
int main(void) {
    int N;
    scanf("%d", &N);
 
    for(int i = 0; i < N; i++) {
        scanf("%d", &deck[i]);
    }
 
    memset(mem, 0, 128);
    //memory: 0, not seen
    //1, outputted already
 
    for(int i = 0; i < N; i++) {
        printf("%d", i);
 
        int flag = 0;
        for(int j = mem[deck[i]]; j < i; j++) {
            if(deck[j] == deck[i]) {
                printf(" %d", j);
                flag = 1;
            }
        }
 
        if(flag == 1) {
            mem[deck[i]] = i+1;
            printf(" %d", deck[i]);
        }
        printf("\n");
    }
}
