#include <stdio.h>
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int knapsack(int w, int wts[], int val[], int n) {
    if(w == 0 || n == 0)
        return 0;
 
    if(wts[n-1] > w)
        return knapsack(w, wts, val, n-1);
 
    else return max(val[n-1] + knapsack(w-wts[n-1], wts, val, n-1),
        knapsack(w, wts, val, n-1));
}
 
int main(void) {
    int n; // num items
    int w; // weight knapsack
    scanf("%d%d", &n, &w);
 
    int wts[n], val[n];
 
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &wts[i], &val[i]);
    }
 
    int maxW = knapsack(w, wts, val, n);
 
    printf("%d\n", maxW);
 
    return 0;
}
