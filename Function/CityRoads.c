#include <stdio.h>
#include "intersection.h"
 
void intersection(int map[100][100], int result[4]) {
    int i, x, y;
    int top, bottom, left, right;
 
    for(i = 0; i < 4; i++) result[i] = 0;
 
    for(x = 0; x < 100; x++) {
        for(y = 0; y < 100; y++) {
            if(map[x][y] != 1) continue;
            top = 0, bottom = 0, left = 0, right = 0;
 
            if(y > 0) top = map[x][y-1];
            if(y < 99) bottom = map[x][y+1];
            if(x > 0) left = map[x-1][y];
            if(x < 99) right = map[x+1][y];
            int sum = top + bottom + left + right;
 
            if(sum == 4) result[0]++;
            else if(sum == 3) result[1]++;
            else if(bottom == 1 && left == 1 || bottom == 1 && right == 1
            || top == 1 && left == 1 || top == 1 && right == 1) {
                result[2]++;
                //printf("x and y: %d, %d\n", x, y);
            }
            else if(sum == 1) {
                result[3]++;
            }
        }
    }
}
