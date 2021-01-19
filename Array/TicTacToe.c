#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
void printBoard(int board[3][3]);
bool isLegal(int x, int y, int board[3][3]);
void result(int board[3][3], int turn);
void win(int turn);
 
main() {
    int board[3][3];
 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = -1;
        }
    }
 
#ifdef DEBUG
    printBoard(board);
#endif
 
    int moves;
    scanf("%d", &moves);
 
    int nextX, nextY;
 
    //black player = 0
    //white player = 1
    int turn = 0;
 
    for(int i = 0; i < moves; i++) {
        scanf("%d%d", &nextX, &nextY);
#ifdef DEBUG
        printf("x: %d, y: %d\n", nextX, nextY);
#endif
 
        if(isLegal(nextX, nextY, board)) {
            board[nextX][nextY] = turn;
#ifdef DEBUG
            printBoard(board);
#endif
 
 
 
            result(board, turn);
 
            if(turn == 1) turn = 0;
            else turn = 1;
        } else {
#ifdef DEBUG
            printf("ILLEGAL\n\n");
#endif
        }
    }
    printf("There is a draw.");
 
    return 0;
}
 
void result(int board[3][3], int turn) {
    int vertCount, horizCount;
 
    for(int i = 0; i < 3; i++) {
        vertCount = 0;
        horizCount = 0;
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == turn) horizCount++;
            if(board[j][i] == turn) vertCount++;
        }
        if(vertCount == 3 || horizCount == 3) {
#ifdef DEBUG
            printf("vertCount: %d, horizCount: %d\n", vertCount, horizCount);
#endif
            win(turn);
        }
    }
 
    if((board[0][0] == turn && board[1][1] == turn && board[2][2] == turn)
    || (board[2][0] == turn && board[1][1] == turn && board [0][2] == turn)) {
        win(turn);
    }
 
}
 
void win(int turn) {
    if(turn == 0) {
        printf("Black wins.");
        exit(0);
    } else if(turn == 1) {
        printf("White wins.");
        exit(0);
    }
}
 
bool isLegal(int x, int y, int board[3][3]) {
    if(x >= 0 && x < 3 && y >= 0 && y < 3
    && board[x][y] == -1) return true;
    return false;
}
 
void printBoard(int board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%4d", board[i][j]);
        }
        puts("");
    }
    printf("\n");
}
