#include <stdio.h>
#include <stdint.h>
 
int matrixArr[8][8];
 
void setMatrix(uint64_t *matrix) {
    uint64_t bit = ((uint64_t)1);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(bit & *matrix)
                matrixArr[i][j] = 1;
            else
                matrixArr[i][j] = 0;
            bit <<= 1;
        }
    }
}
 
void printMatrix(uint64_t *matrix) {
    printf("%lu\n", *matrix);
    setMatrix(matrix);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d", matrixArr[i][j]);
        }
        printf("\n");
    }
}
 
void rotateMatrix(uint64_t *matrix) {
    setMatrix(matrix);
 
    *matrix = 0;
    uint64_t bit = ((uint64_t)1);
    for(int j = 0; j < 8; j++) {
        for(int i = 7; i >= 0; i--) {
            if(matrixArr[i][j])
                *matrix += bit;
            bit <<= 1;
        }
    }
}
 
void transposeMatrix(uint64_t *matrix) {
    setMatrix(matrix);
 
    *matrix = 0;
    uint64_t bit = ((uint64_t)1);
 
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(matrixArr[j][i])
                *matrix += bit;
            bit <<= 1;
        }
    }
}
