#include <stdio.h>
 
void snake(const int *ptr_array[100][100], int m) {
    int sizeTemp = m*m;
    const int *tmp_array[sizeTemp];
    int counter = 0;
    int i, j;
    int dir = 0;
#ifdef DEBUG
    printf("- - -\n");
#endif
    for(i = 0; i < m; i++) {
        if(dir == 0) {
            for(j = 0; j < m; j++) {
                tmp_array[counter] = ptr_array[i][j];
                counter++;
            }
        } else if(dir == 1) {
            for(j = m-1; j >= 0; j--) {
                tmp_array[counter] = ptr_array[i][j];
                counter++;
            }
        }
        dir ^= 1;
    }
 
    for(i = 0; i < sizeTemp-1; i++) {
        for(j = 0; j < sizeTemp-i-1; j++) {
            if(*(tmp_array[j]) > *(tmp_array[j+1])) {
                const int *tmp = tmp_array[j];
                tmp_array[j] = tmp_array[j+1];
                tmp_array[j+1] = tmp;
            }
        }
    }
 
#ifdef DEBUG
    for(int i = 0; i < sizeTemp; i++) {
        printf("%d ", *(tmp_array[i]));
        if((i+1) % 3 == 0) printf("\n");
    }
    printf("- - -\n");
#endif
 
    dir = 0;
    counter = 0;
    for(i = 0; i < m; i++) {
        if(dir == 0) {
            for(j = 0; j < m; j++) {
                ptr_array[i][j] = tmp_array[counter];
                counter++;
            }
        } else if(dir == 1) {
            for(j = m-1; j >= 0; j--) {
                ptr_array[i][j] = tmp_array[counter];
                counter++;
            }
        }
        dir ^= 1;
    }
}
