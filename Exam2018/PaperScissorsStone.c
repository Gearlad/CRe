#include <stdio.h>
 
int a, b, c, d, e, f, X0, Y0;
 
enum TYPE { PAPER, SCISSORS, STONE };
enum RES { XWIN, YWIN, DRAW };
 
int X(int t, int XP) {
    return (a*XP+b)%c;
}
 
int Y(int t, int YP) {
    return (d*YP+e)%f;
}
 
int win(int a, int b) {
    if(a == b) return DRAW;
    if(a == PAPER && b == SCISSORS ||
        a == SCISSORS && b == STONE ||
        a == STONE && b == PAPER) return YWIN;
    return XWIN;
}
 
int main(void) {
    int N;
    scanf("%d%d%d%d", &X0, &a, &b, &c);
    scanf("%d%d%d%d", &Y0, &d, &e, &f);
    scanf("%d", &N);
 
    for(int i = 0; i < N; i++) {
        int k = 1;
        int result;
        for(k = 1;; k++) {
            result = win(X0%3, Y0%3);
            X0 = X(i, X0), Y0 = Y(i, Y0);
            if(result != DRAW) goto VICTORY;
        }
 
        VICTORY:
        printf("%d %d\n", result, k);
    }
 
    return 0;
}
