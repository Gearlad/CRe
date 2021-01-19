#include <stdio.h>
 
void printBoard(int ax, int ay, int bx, int by);
 
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}
 
int boxWidth, boxHeight;
 
void boxCollision(int x, int y, int *xVel, int *yVel) {
    if(x <= 1 || x == boxWidth) *xVel *= -1;
    if(y <= 1 || y == boxHeight) *yVel *= -1;
}
 
int main(void) {
    scanf("%d%d", &boxWidth, &boxHeight);
 
    int ax, ay, bx, by;
    scanf("%d%d%d%d", &ax, &ay, &bx, &by);
 
    int axVel, ayVel, bxVel, byVel;
    scanf("%d%d%d%d", &axVel, &ayVel, &bxVel, &byVel);
 
 
    int timer;
    scanf("%d", &timer);
 
    /*printf("INITIAL Ax: %d, Ay: %d\n", ax, ay);
    printf("INITIAL Bx: %d, By: %d\n", bx, by);
    printBoard(ax, ay, bx, by);*/
    for(int i = 0; i < timer; i++) {
        boxCollision(ax, ay, &axVel, &ayVel);
        boxCollision(bx, by, &bxVel, &byVel);
 
        //printf("Ax: %d, Ay: %d\n", ax, ay);
        //printf("Bx: %d, By: %d\n", bx, by);
 
        if(ax == bx && ay == by) {
            swap(&axVel, &bxVel);
            swap(&ayVel, &byVel);
        }
 
        //printBoard(ax, ay, bx, by);
 
        ax += axVel, ay += ayVel;
        bx += bxVel, by += byVel;
    }
    printf("%d\n%d\n%d\n%d\n", ax, ay, bx, by);
 
    return 0;
}
 
void printBoard(int ax, int ay, int bx, int by) {
    for(int i = 1; i < boxHeight; i++) {
        printf("%d\t", i);
        for(int j = 1; j < boxWidth; j++) {
            if(i == by && j == bx && i == ay && j == ax) printf("Z~");
            else if(i == ay && j == ax) printf("A");
            else if(i == by && j == bx) printf("B");
            else printf("_");
        }
        printf("\n");
    }
    printf("\n\n");
}
