#include <stdio.h>
 
int main(void) {
    int sum = 0;
    int curr;
    while(scanf("%d", &curr) != EOF) { sum += curr; }
 
    printf("%d\n", sum);
}
