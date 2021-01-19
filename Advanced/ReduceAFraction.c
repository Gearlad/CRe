#include <stdio.h>
#include <math.h>
#include <stdlib.h>
 
int min(int a, int b) { return a < b ? a : b; }
 
int gcdCalc(int a, int b) {
    if(a == 0)
        return b;
    return gcdCalc(b%a, a);
}
 
int main(void) {
    int a, b;
 
    while(scanf("%d%d", &a, &b) == 2) {
        int gcd = gcdCalc(a, b);
        printf("%d / %d\n", (a/gcd), (b/gcd));
    }
 
    return 0;
}
