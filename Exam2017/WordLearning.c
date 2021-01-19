#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
int T;
 
int mat[26][26] = 0;
 
char out[26];
int out_len = 0;
 
void print_mat() {
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            printf("%d%c", mat[i][j], j == 25 ? '\n' : ' ');
        }
    }
}
 
int char_to_int(char a) {
    return a - 'a';
}
 
char int_to_char(int a) {
    return a + 'a';
}
 
void append(char a) {
    out_len++;
    out[out_len-1] = a;
    out[out_len] = '\0';
}
 
int main(void) {
#ifdef DEBUG
    print_mat();
#endif
 
    scanf("%d", &T);
 
    char in[100];
    while(scanf("%s", in) == 1) {
        int len = strlen(in);
        for(int i = 1; i < len; i++) {
            mat[char_to_int(in[i-1])][char_to_int(in[i])]++;
        }
    }
 
 
    int x = 0, y = 0, max = -1;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++) {
            if(mat[i][j] > max) {
                x = i, y = j, max = mat[i][j];
            }
        }
    }
 
    bool used[26] = {};
    append(int_to_char(x));
    append(int_to_char(y));
 
    used[x] = used[y] = true;
    while((x=y) >= 0) {
        y = -1, max = -1;
        for(int i = 0; i < 26; i++) {
            if(mat[x][i] > max && !used[i]) {
                max = mat[x][i], y = i;
            }
        }
        if(max > T) {
            append(int_to_char(y));
            used[y] = true;
        } else {
            y = -1;
        }
    }
 
 
    print_mat();
    puts(out);
    return 0;
}
