#include <stdio.h>
 
int W = 0;
int D = 0;
 
main() {
    scanf("%d%d", &W, &D);
 
    int room[D+2][W+2];
 
    room[0][0] = -1111;
    room[0][W+1] = -1111;
    room[D+1][0] = -1111;
    room[D+1][W+1] = -1111;
 
 
    /*
    Input: 5x5
 
    1 0 1 0 1 ---- 1
    0 0 1 0 0
    0 1 1 0 0
    1 1 0 0 1
    1 0 0 0 0 ---- 5
    |       |
    |       |
    1       5
 
    Array: 7x7
  x 13 121110 x ---- 0
 14 1 0 1 0 1 9
 15 0 0 1 0 0 8
 16 0 1 1 0 0 7
 17 1 1 0 0 1 6
 18 1 0 0 0 0 5 ---- D
  x 0 1 2 3 4 x ---- D+1
  |         | |
  |         | |
  0         W W+1  */
 
 
    int counter = 0;
 
    //1 to W, D+1`
    for(int i = 1; i < W+1; i++) {
        room[D+1][i] = counter;
        counter++;
    }
 
    //W+1, D to 1
    for(int i = D; i >= 1; i--) {
        room[i][W+1] = counter;
        counter++;
    }
 
    //W to 1, 0
    for(int i = W; i >= 1; i--) {
        room[0][i] = counter;
        counter++;
    }
 
    //0, 1 to D
    for(int i = 1; i <= D; i++) {
        room[i][0] = counter;
        counter++;
    }
 
 
    //1 to 5, 1 to 5
    for(int i = 1; i <= D; i++) {
        for(int j = 1; j <= W; j++) {
            scanf("%d", &room[i][j]);
        }
    }
 
    /*for(int i = 0; i <= D + 1; i++) {
        for(int j = 0; j <= W + 1; j++) {
            printf("%d\t", room[i][j]);
        }
        printf("\n");
    }*/
 
 
    int x, y, xVel, yVel;
 
    //bottom side
    for(int i = 1; i <= W; i++) {
        x = i;
        y = D;
        xVel = 0;
        yVel = -1;
        while(x <= W && y > 0) {
            /*printf("x, y: %d, %d\n", x, y);
            printf("room: %d\n", room[y][x]);
            printf("xVel = %d\n", xVel);
            printf("yVel = %d\n", yVel);*/
 
            if(room[y][x] == 1) {
                xVel = xVel == 0 ? 1 : 0;
                yVel = yVel == -1 ? 0 : -1;
            }
            x += xVel;
            y += yVel;
        }
        printf("%d\n", room[y][x]);
    }
 
    //right side
    for(int i = D; i >= 1; i--) {
        x = W;
        y = i;
        xVel = -1;
        yVel = 0;
        while(x >= 1 && y <= D) {
            if(room[y][x] == 1) {
                xVel = xVel == -1 ? 0 : -1;
                yVel = yVel == 0 ? 1 : 0;
            }
            x += xVel;
            y += yVel;
        }
        printf("%d\n", room[y][x]);
    }
 
    //top side
    for(int i = W; i >= 1; i--) {
        x = i;
        y = 1;
        xVel = 0;
        yVel = 1;
        while(x >= 1 && y <= D) {
            if(room[y][x] == 1) {
                xVel = xVel == 0 ? -1 : 0;
                yVel = yVel == 1 ? 0 : 1;
            }
            x += xVel;
            y += yVel;
        }
        printf("%d\n", room[y][x]);
    }
 
    //left side
    for(int i = 1; i <= D; i++) {
        x = 1;
        y = i;
        xVel = 1;
        yVel = 0;
        while(x <= W && y >= 1) {
            if(room[y][x] == 1) {
                xVel = xVel == 1 ? 0 : 1;
                yVel = yVel == 0 ? -1 : 0;
            }
            x += xVel;
            y += yVel;
        }
        printf("%d\n", room[y][x]);
    }
}
