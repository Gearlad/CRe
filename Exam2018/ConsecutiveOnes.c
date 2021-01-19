#include <stdio.h>
#include <stdbool.h>
 
int main() {
    int longestVertical = 0, longestHoriz = 0, longestDiagonal = 0;
 
    int a;
    scanf("%d", &a);
 
    int arr[a][a];
 
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
 
    int currHoriz;
    int currVertic;
 
    int arrClone[a][a];
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a; j++) {
            arrClone[i][j] = 0;
        }
    }
 
    for(int i = 0; i < a; i++) {
        currHoriz = 0;
        currVertic = 0;
        for(int j = 0; j < a; j++) {
            if(arr[i][j] == 1) {
 
                //diagonal
                if(i == 0 || j == 0) arrClone[i][j] = 1;
                else {
                    arrClone[i][j] = arrClone[i-1][j-1] + 1;
                }
                if(arrClone[i][j] >= longestDiagonal) longestDiagonal = arrClone[i][j];
 
                //horizontal
                currHoriz++;
                if(currHoriz >= longestHoriz) longestHoriz = currHoriz;
            } else if(arr[i][j] == 0) {
                currHoriz = 0;
                arrClone[i][j] = 0;
            }
 
 
            //vertical
            if(arr[j][i] == 1) {
                currVertic++;
                if(currVertic >= longestVertical) longestVertical = currVertic;
            } else if(arr[j][i] == 0) {
                currVertic = 0;
            }
        }
        currHoriz = 0;
        currVertic = 0;
    }
 
 
#ifdef DEBUG
    for(int i = 0 ; i < a; i++) {
        for(int j = 0; j < a; j++) {
            printf("%d ", arrClone[i][j]);
        }
        printf("\n");
    }
    printf("longest vertical: %d\n", longestVertical);
    printf("longest diagonal: %d\n", longestDiagonal);
    printf("longest Horiz: %d\n", longestHoriz);
#endif
    int longest = longestHoriz;
    if(longestVertical > longest) longest = longestVertical;
    if(longestDiagonal > longest) longest = longestDiagonal;
 
    printf("%d", longest);
    return 0;
}
