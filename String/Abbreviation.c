#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
 
int main(void) {
 
    char input[127];
    char abbreviation[127];
    char ignored[4][20] = {"of", "and", "the", "at"};
 
    while(scanf("%s", input) != EOF) {
 
        int inputLength = strlen(input);
 
#ifdef DEBUG
        puts(input);
#endif
        char compare[127];
        strcpy(compare, input);
        if(compare[inputLength-1] == '.') compare[inputLength-1] = '\0';
 
        bool process = true;
        for(int i = 0; i < 4; i++) {
            if(!strcmp(compare, ignored[i])) process = false;
        }
#ifdef DEBUG
        printf("PROCESS: %d\n\n", process);
#endif
 
        if(process == false) {
            if(input[inputLength-1] == '.') puts("");
            continue;
        }
 
        putchar(toupper(input[0]));
        if(input[inputLength-1] == '.') puts("");
 
    }
 
    return 0;
}
