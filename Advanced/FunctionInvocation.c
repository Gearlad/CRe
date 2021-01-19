#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int g(int z) {
    if(z <= 2)
        return (int)(pow(z, 2)-1);
    return 2;
}
 
int h(int y) {
    if(y < 2)
        return -1;
    return 2 + h(y-1) - h(y-2);
}
 
int f(int x) {
    if(x > h(x))
        return f(x-1) - h(x);
    else if(x < h(x))
        return f(g(x)) - g(x);
    return 1;
}
 
int main(void) {
    int x;
    scanf("%d", &x);
    int res = f(x);
 
    printf("%d\n", res);
 
    return 0;
}
