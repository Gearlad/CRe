#include <stdio.h>
 
int count(int a, int b);
int counter = 0;
 
main() {
    int r, c;
    scanf("%d%d", &r, &c);
 
    int final = count(r, c);
    printf("%d", final);
    return 0;
}
 
int count(int a, int b) {
    if(a <= 1 || b <= 1) return 1;
    return count(a-1, b) + count(a, b-1);
}
