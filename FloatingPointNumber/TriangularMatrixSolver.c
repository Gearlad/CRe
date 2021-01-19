#include <stdio.h>
 
int main() {
 
    int n = 0;
    scanf("%d", &n);
 
    int i, j;
    double A[n][n];
 
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
 
 
 
    double Y[n];
 
    for(i = 0; i < n; i++) {
        scanf("%lf", &Y[i]);
    }
 
 
 
    double X[n];
 
 
    X[n-1] = Y[n-1]/A[n-1][n-1];
 
    for(i = n-2; i >= 0; i--) {
        double tempSum = 0.0;
        for(j = n-1; j > i; j--) {
            tempSum += A[i][j] * X[j];
        }
 
        X[i] = (Y[i]-tempSum)/A[i][i];
    }
 
 
    for(int i = 0; i < n; i++) {
        printf("%f\n", X[i]);
    }
 
    return 0;
 
}
