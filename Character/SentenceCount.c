#include <stdio.h>
#include <ctype.h>
char buf[1<<20] = {};
int main() {
    fread(buf, 1, 1<<20, stdin);
    int out = 0;
    for(int i = 0; buf[i]; i++) {
        if(buf[i] == '.') {
            if(buf[i+1] == ' ' && buf[i+2] == ' ')
                out++;
            else if(buf[i+1] == '\n' || buf[i+1] == '\0')
                out++;
        }
    }
    printf("%d\n", out);
    return 0;
}
