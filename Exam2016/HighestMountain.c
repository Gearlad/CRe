#include <stdio.h>
 
int main(void) {
 
    int n, m;
 
    scanf("%d %d", &n, &m);
 
    int maxRow = 0;
    int maxCol = 0;
    int max = -1;
 
    for(int i = 0; i < n; i++) {
 
        int currMax = -1;
        int secMax = -1;
 
        int currMaxCol = 0;
        int secMaxCol = 0;
 
        int curr;
 
 
        for(int j = 0; j < m; j++) {
            scanf("%d", &curr);
 
            if(curr >= max) {
                max = curr;
                maxRow = i;
                maxCol = j;
            }
 
            if(curr >= currMax) {
                if(currMax >= secMax) {
                    secMax = currMax;
                    secMaxCol = currMaxCol;
                }
                currMax = curr;
                currMaxCol = j;
            } else if(curr >= secMax) {
                secMax = curr;
                secMaxCol = j;
            }
 
        }
        printf("%d %d\n", currMaxCol + 1, secMaxCol + 1);
    }
 
 
    printf("%d %d\n", maxRow + 1, maxCol + 1);
 
    return 0;
}
