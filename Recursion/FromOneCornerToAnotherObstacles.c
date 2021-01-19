#include <stdio.h>
#include <string.h>
 
#define MAXN 12
 
int matrix[MAXN][MAXN];
 
int main(void) {
    int r, c;
    scanf("%d%d", &r, &c);
 
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++){
            scanf("%d", &(matrix[i][j]));
        }
    }
 
    int dp[r][c];
    memset(dp, 0, sizeof(dp[0][0])*r*c);
 
    for(int i = 0; i < r; i++)
    dp[r-1][0] = matrix[r-1][0];
 
    for(int i = 0; i < c; i++) {
        if(matrix[r-1][i] == 0) break;
        dp[r-1][i] = 1;
    }
 
    for(int i = r-1; i >= 0; i--) {
        if(matrix[i][0] == 0) break;
        dp[i][0] = 1;
    }
 
    int minX = 1;
    for(int i = r-2; i >= 0; i--) {
        for(int j = minX; j < c; j++) {
            if(matrix[i][j] == 0)
                continue;
            else
                dp[i][j] = dp[i+1][j] + dp[i][j-1];
        }
    }
#ifdef DEBUG
    printf("------\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    printf("------\n");
#endif
 
    printf("%d\n", dp[0][c-1]);
    return 0;
}
