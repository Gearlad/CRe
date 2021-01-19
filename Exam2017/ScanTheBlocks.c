#include <stdio.h>
 
main() {
    int a, b;
 
    scanf("%d%d", &a, &b);
 
    int total = 0;
    for(int i = a; i <= b; i++) {
        total += i;
    }
 
    int aroundTotal = a + b + 2*((b-a) - 1);
 
 
    printf("%d\n%d\n", total, aroundTotal);
    return 0;
}
