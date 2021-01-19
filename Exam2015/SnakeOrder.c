#include "snake.h"
#include <stdio.h>
 
int arrSize(int *ptr) {
    int i = 1;
    while(ptr[i] != 0) {
        i++;
    }
    return i;
}
 
int correct(int x, int r, int C, int c1) {
    return x == ((r*C) + c1);
}
 
void printArr(int *ptr) {
    printf("%d ", *ptr);
    int i = 1;
    while(ptr[i] != 0) {
        printf("%d ", *(ptr+i));
        i++;
    }
    return;
}
 
int snake(int *ptr, int *row, int *column) {
    *row = 1, *column = -1;
    for(int i = 1; ptr[i]; i++) {
        if(ptr[i] != ptr[i-1]+1) {
            *column = i;
            break;
        }
    }
 
    int n = 1;
    for(int i = 1; ptr[i]; i++, n++);
    if(*column < 0) *column = n;
    *row = n / *column;
 
    int *A = ptr, status = 1;
    for(int i = 0, pos = 0; i < *row; i++) {
        if(i%2 == 0) {
            for(int j = 0; j < *column; j++) {
                status &= *A == pos+j, A++;
                if(!status) {
                    *row = i, *column = j;
                    return 0;
                }
            }
        } else {
            for(int j = *column-1; j >= 0; j--) {
                status &= *A == pos+j, A++;
                if(!status) {
                    *row = i, *column = j;
                    return 0;
                }
            }
        }
        pos += *column;
    }
    return status;
}
