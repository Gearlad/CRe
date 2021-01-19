#include <stdio.h>
 
int rectArea(int x1, int y1, int x2, int y2);
 
int max(int a, int b);
int min(int a, int b);
 
main() {
    int arr[3][2][2];
    //arr[rectangleNo][bottom/top][x/y]
 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
 
    int diffX = arr[0][0][0];
    int diffY = arr[0][0][1];
 
    for(int i = 0; i < 3; i++) {
        if(arr[i][0][0] < diffX) diffX = arr[i][0][0];
        if(arr[i][0][1] < diffY) diffY = arr[i][0][1];
    }
 
    if(diffX < 0) diffX = -diffX;
    if(diffY < 0) diffY = -diffY;
 
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 2; j++) {
            arr[i][j][0] += diffX;
            arr[i][j][1] += diffY;
        }
    }
 
    //printf("\n");
    //printf("diff: %d, %d\n", diffX, diffY);
 
    //print new coordinate values
    /*for(int i = 0; i < 3; i++) {
        printf("%d, %d, %d, %d\n", arr[i][0][0], arr[i][0][1], arr[i][1][0], arr[i][1][1]);
    }*/
 
    int area = 0;
 
    //calculate total area
    for(int i = 0; i < 3; i++) {
        area += rectArea(arr[i][0][0], arr[i][0][1], arr[i][1][0], arr[i][1][1]);
    }
 
    //printf("%d\n", area);
 
    //steps for CALCULATING OVERLAPPING AREA
    //calculate overlapping area of A and B, and subtract it
    //left = calculate the maximum of the bottom left x values
    //bottom = calculate the maximum of the bottom left y values
    //right = calculate the minimum of the top right x values
    //top = calculate the minumum of the top right y values
    //if left < right and bottom < top, there is intersection
    //if intersection, then subtract area of this new rectangle
 
    //AB
    int leftAB = max(arr[0][0][0], arr[1][0][0]);
    int bottomAB = max(arr[0][0][1], arr[1][0][1]);
    int topAB = min(arr[0][1][1], arr[1][1][1]);
    int rightAB = min(arr[0][1][0], arr[1][1][0]);
 
    //printf("AB left: %d, bottom: %d, top: %d, right: %d\n", leftAB, bottomAB, topAB, rightAB);
 
    if(leftAB < rightAB && bottomAB < topAB) area -= rectArea(leftAB, bottomAB, rightAB, topAB);
 
    //calculate overlapping area of B and C, and subtract it
    int leftBC = max(arr[1][0][0], arr[2][0][0]);
    int bottomBC = max(arr[1][0][1], arr[2][0][1]);
    int topBC = min(arr[1][1][1], arr[2][1][1]);
    int rightBC = min(arr[1][1][0], arr[2][1][0]);
 
    //printf("BC left: %d, bottom: %d, top: %d, right: %d\n", leftBC, bottomBC, topBC, rightBC);
 
    if(leftBC < rightBC && bottomBC < topBC) area -= rectArea(leftBC, bottomBC, rightBC, topBC);
 
    //calculate overlapping area of A and C, and subtract it
    int leftAC = max(arr[0][0][0], arr[2][0][0]);
    int bottomAC = max(arr[0][0][1], arr[2][0][1]);
    int topAC = min(arr[0][1][1], arr[2][1][1]);
    int rightAC = min(arr[0][1][0], arr[2][1][0]);
 
    //printf("AC left: %d, bottom: %d, top: %d, right: %d\n", leftAC, bottomAC, topAC, rightAC);
 
    if(leftAC < rightAC && bottomAC < topAC) area -= rectArea(leftAC, bottomAC, rightAC, topAC);
 
    //finally, add back the overlapping area of A, B, and C
    int leftABC = max(leftAB, leftBC);
    leftABC = max(leftABC, leftAC);
    int bottomABC = max(bottomAB, bottomBC);
    bottomABC = max(bottomABC, bottomAC);
    int topABC = min(topAB, topBC);
    topABC = min(topABC, topAC);
    int rightABC = min(rightAB, rightBC);
    rightABC = min(rightABC, rightAC);
 
    //printf("ABC overlap: %d, %d, %d, %d\n", leftABC, bottomABC, topABC, rightABC);
 
    if(leftABC < rightABC && bottomABC < topABC) area += rectArea(leftABC, bottomABC, rightABC, topABC);
 
    printf("%d", area);
 
    return 0;
}
 
int max(int a, int b) {
    return a > b ? a : b;
}
 
int min(int a, int b) {
    return a < b ? a : b;
}
 
int rectArea(int x1, int y1, int x2, int y2) {
    return (x2-x1) * (y2-y1);
}
