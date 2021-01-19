#include <stdio.h>
 
main() {
    int n;
    scanf("%d", &n);
 
    int city[n+2][n+2];
 
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &city[i][j]);
        }
    }
 
    for(int i = 0; i <= n+1; i++) {
        city[0][i] = 0;
        city[i][0] = 0;
        city[n+1][i] = 0;
        city[i][n+1] = 0;
    }
 
   /*printf("\n");
 
    for(int i = 0; i <= n+1; i++) {
        for(int j = 0; j <= n+1; j++) {
            printf("%d ", city[i][j]);
        }
        printf("\n");
    }*/
 
    //DEAD END: 1 connected road bit
    //TURN: 2 connected road bits, not in line
    //T-JUNCTION: 3 connected road bits
    //INTERSECTION: 4 connected road bits on all sides of it
 
    int dend = 0;
    int turn = 0;
    int tjun = 0;
    int insc = 0;
 
    for(int x = 1; x <= n; x++) {
        for(int y = 1; y <= n; y++) {
            int center = city[x][y];
            if(center == 1) {
                int top = city[x][y-1];
                int bottom = city[x][y+1];
                int left = city[x-1][y];
                int right = city[x+1][y];
                int sum = top + bottom + left + right;
 
                if(sum == 4) insc++;
                else if(sum == 3) tjun++;
                else if(bottom == 1 && left == 1 || bottom == 1 && right == 1
                || top == 1 && left == 1 || top == 1 && right == 1) {
                    turn++;
                    //printf("x and y: %d, %d\n", x, y);
                }
                else if(sum == 1) {
                    dend++;
                }
            }
        }
    }
 
    printf("%d\n%d\n%d\n%d\n", insc, tjun, turn, dend);
    return 0;
}
