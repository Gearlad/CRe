#include <stdio.h>
#include <stdlib.h>
 
int n, A[16];
 
#define swap(a, b) { int tmp; tmp = a, a = b, b = tmp; }
 
int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return x == y ? 0 : (x < y ? -1 : 1);
}
 
int next_perm(int A[], int n) {
    for(int i = n-2; i >= 0; i--) {
        if(A[i] >= A[i+1]) continue;
        int j = i+1;
        while(j < n && A[j] > A[i]) j++;
        j--;
        swap(A[i], A[j]);
        for(int p = i+1, q = n-1; p < q; p++, q--)
            swap(A[p], A[q]);
        return 1;
    }
    return 0;
}
 
int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    qsort(A, n, sizeof(int), cmp);
    do {
        for(int i = 0; i < n; i++) {
            printf("%d%c", A[i], i == n-1 ? '\n' : ' ');
        }
    } while(next_perm(A, n));
 
    return 0;
}
