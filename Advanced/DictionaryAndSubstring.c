#include <stdio.h>
#include <string.h>
 
#define MAXL 50
 
char dict[200][MAXL];
 
int main(void) {
    int N;
    scanf("%d", &N);
 
    for(int i = 0; i < N; i++) {
        scanf("%s", dict[i]);
    }
 
    int Q;
    scanf("%d", &Q);
 
    char sub[MAXL];
 
    for(int i = 0; i < Q; i++) {
        int c = 0;
 
        scanf("%s", sub);
 
        for(int j = 0; j < N; j++) {
            if(strstr(dict[j], sub) != NULL) c++;
        }
        printf("%d\n", c);
    }
 
    return 0;
}
