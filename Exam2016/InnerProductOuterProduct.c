#include <stdio.h>
 
int main(void) {
    int inner;
    int cross[3];
 
    int a, b, c, d, e, f;
 
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
 
    inner = a*d + b*e + c*f;
 
    printf("%d\n", inner);
 
    cross[0] = b*f - c*e;
    cross[1] = c*d - a*f;
    cross[2] = a*e - b*d;
 
    printf("%d %d %d", cross[0], cross[1], cross[2]);
 
    return 0;
}
