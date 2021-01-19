	
#include <stdio.h>
#include <stdlib.h>
 
int gcfCalculator(int x, int y);
int lcmCalculator(int x, int y);
 
main() {
    int arrSize = 10;
 
    //int *arr = (int *) malloc(arrSize * sizeof(int));
    //char temp;
 
    //i represents number of ints input
    int a, b = 0;
    scanf("%d", &a);
    int lcm = a;
 
    while(scanf("%d", &b) != EOF) {
        lcm = lcmCalculator(b, lcm);
    }
 
    printf("%d", lcm);
}
 
int gcfCalculator(int x, int y) {
    if(y == 0) return x;
    return gcfCalculator(y, x % y);
}
 
int lcmCalculator(int x, int y) {
    return (x * y) / gcfCalculator(x, y);
}
