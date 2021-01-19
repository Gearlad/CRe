#include <stdio.h>
 
int sumSq(int a, int sum);
 
main() {
    int n;
    scanf("%d", &n);
    n = sumSq(n, 0);
    printf("%d", n);
    return 0;
}
 
int sumSq(int a, int sum) {
    if(a < 1) return sum;
 
    sum += a*a;
    a -= 1;
    sumSq(a, sum);
}
