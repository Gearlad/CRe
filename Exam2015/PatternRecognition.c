#include <stdio.h>
#include <stdlib.h>
 
int main(void) {
    int n, k, m, d;
 
    scanf("%d %d %d %d", &n, &k, &m, &d);
 
    int matrix1[n][n];
    int matrix2[k][k];
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }
 
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }
 
    int x = -1, y =-1;
    int mCount, sum1, sum2;
 
    for(int i = 0; i <= n-k; i++) {
        for(int j = 0; j <= n-k; j++) {
            mCount = 0;
            sum1 = 0;
            sum2 = 0;
 
            for(int a = i; a < i + k; a++) {
                for(int b = j; b < j + k; b++) {
 
#ifdef DEBUG
    printf("%d %d\n", a-i, b-j);
#endif
                    sum1 += matrix1[a][b];
                    sum2 += matrix2[a-i][b-j];
                    if(matrix1[a][b] != matrix2[a-i][b-j]) mCount++;
                }
            }
            if(abs(sum1-sum2) <= d && mCount <= m) {
                x = i;
                y = j;
            }
        }
    }
 
    printf("%d %d\n", x, y);
 
 
 
    return 0;
}
