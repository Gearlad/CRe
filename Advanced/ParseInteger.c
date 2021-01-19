#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
 
#define MAXN 1000*5
 
int main(void) {
 
#ifdef DEBUG
    printf("%s", line);
#endif
 
    char line[MAXN];
 
    while(scanf("%s", line) == 1) {
        char *ptr = line;
        while(*ptr) {
            if(isdigit(*ptr)) {
                long val = strtol(ptr, &ptr, 10);
                printf("%ld\n", val);
            } else {
                ptr++;
            }
        }
    }
 
    return 0;
}
