#include <stdio.h>
 
int main(void) {
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
 
    int numEdge = (a+b+c+d+f+g)+(a*e)+(b*e)+(c*e)+(c*f)+(d*f)+(e*g);
    int numPath = g*(a*e + b*e + c*e) + c*f + d*f;
 
    printf("%d\n%d\n", numEdge, numPath);
}
