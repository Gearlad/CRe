#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAXS 128
 
int main(void) {
 
    char curr[MAXS];
    while(gets(curr)) {
        int i = 0;
        while(isspace(curr[i])) { i++; }
 
        int j = strlen(curr)-1;
        while(isspace(curr[j])) { j--; }
 
        for(int k = i; k <= j; k++) {
            printf("%c", curr[k]);
        }
        printf("\n");
    }
 
 
    return 0;
}
