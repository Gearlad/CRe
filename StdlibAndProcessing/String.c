#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAXN 128
 
int main(void) {
    char line[MAXN][MAXN];
 
    int l = 0;
    while(gets(line[l]) != NULL) { l++; }
 
    qsort(line, l, MAXN, strcmp);
 
    for(int i = 0; i < l; i++) {
        puts(line[i]);
    }
 
    return 0;
}
