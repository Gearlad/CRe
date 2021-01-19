#include <stdio.h>
#include <stdlib.h>
 
#define MAXN 1024
 
typedef unsigned long long ull;
 
ull numbers[MAXN];
 
int numOnes(ull num) {
    int count = 0;
    for(int i = 63; i >= 0; i--) {
        ull k = num >> i;
        if(k & 1) count++;
    }
 
    return count;
}
 
int cmp(const void * a, const void * b) {
    ull a1 = *(ull *)a;
    ull b1 = *(ull *)b;
 
    int a1t = numOnes(a1);
    int b1t = numOnes(b1);
 
    if(a1t == b1t) return a1 > b1;
 
    return a1t-b1t;
}
 
int main(void) {
    int i = 0;
    while(scanf("%llu", &(numbers[i])) != EOF) { i++; }
 
    qsort(numbers, i, sizeof(ull), cmp);
 
    for(int x = 0; x < i; x++) {
        printf("%llu\n", numbers[x]);
    }
 
    return 0;
}
