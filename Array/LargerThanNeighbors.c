#include <stdio.h>
 
main() {
    int r, c;
    scanf("%d%d", &r, &c);
 
    int arr[r+2][c+2];
 
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
 
    for(int i = 0; i <= r+1; i++) {
        arr[i][0] = 0;
        arr[0][i] = 0;
        arr[r+1][i] = 0;
        arr[i][c+1] = 0;
    }
 
    /*printf("\n");
    for(int i = 0; i <= r+1; i++) {
        for(int j = 0; j <= c+1; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }*/
 
    for(int x = 1; x <= r; x++) {
        for(int y = 0; y <= c; y++) {
            int center = arr[x][y];
            int top = arr[x][y-1];
            int bottom = arr[x][y+1];
            int left = arr[x-1][y];
            int right = arr[x+1][y];
            if(center > top && center > bottom &&
            center > left && center > right) printf("%d\n", center);
        }
    }
    return 0;
}
