#include <stdio.h>
 
main() {
    int r, c;
    scanf("%d%d", &r, &c);
 
    int arr[r][c];
 
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            //printf("\n%d\n", arr[i][j]);
        }
    }
 
    for(int i = 0; i < c; i++) {
        int average = 0;
        for(int j = 0; j < r; j++) {
            average += arr[j][i];
        }
 
        average /= r;
        printf("%d\n", average);
    }
 
    return 0;
}
