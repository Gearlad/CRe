#include <stdio.h>
 
long long sum(long long m, long long n);
long long factorial(long long x);
//int factorialRecursive(int x);
 
main() {
    long long n, m;
    scanf("%lld%lld", &n, &m);
 
    long long total = 0;
 
    //calculate n factorial
    for(int i = 0; i <= m; i++) {
        long long currentSum = sum(i, n);
        total += sum(i, n);
    }
 
    printf("%lld", total);
 
    return 0;
}
 
long long sum(long long i, long long n) {
 
    //find factorial i and m
    long long factorialM = factorial(i);
    long long factorialN = factorial(n);
 
    //formula
    long long finalSum = factorialN / (factorialM * factorial(n - i));
 
    return finalSum;
}
 
long long factorial(long long x) {
    if(x != 0) {
        for(int i = x-1; i > 0; i--) {
            x *= i;
        }
        return x;
    }
    return 1;
}
