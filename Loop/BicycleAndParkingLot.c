#include <stdio.h>
#include <math.h>
 
int distance(int a, int b);
 
main() {
    int nLots;
    scanf("%d", &nLots);
 
    //0: x
    //1: y
    int parkingLots[nLots][2];
    //bikes / capacity
    int lotCapacity[nLots][2];
 
    for(int i = 0; i < nLots; i++) {
        scanf("%d%d%d", &parkingLots[i][0], &parkingLots[i][1], &lotCapacity[i][1]);
        lotCapacity[i][0] = 0;
    }
 
    int mBikes;
    scanf("%d", &mBikes);
    int bikes[mBikes][2];
 
    for(int i = 0; i < mBikes; i++) {
        scanf("%d%d", &bikes[i][0], &bikes[i][1]);
    }
 
    for(int i = 0; i < mBikes; i++) {
 
        int smallestIndex = -1;
        int smallestXDistance, smallestYDistance;
 
        for(int j = 0; j < nLots; j++) {
            if(lotCapacity[j][0] == lotCapacity[j][1]) continue;
 
            int xDistance = distance(bikes[i][0], parkingLots[j][0]);
            int yDistance = distance(bikes[i][1], parkingLots[j][1]);
 
            if(smallestIndex == -1) {
                smallestIndex = j;
                smallestXDistance = xDistance;
                smallestYDistance = yDistance;
                continue;
            }
 
            if(xDistance + yDistance < smallestXDistance + smallestYDistance) {
                smallestIndex = j;
                smallestXDistance = xDistance;
                smallestYDistance = yDistance;
                continue;
            }
 
            if(xDistance + yDistance == smallestXDistance + smallestYDistance) {
                if(parkingLots[j][0] < parkingLots[smallestIndex][0]) {
                    smallestIndex = j;
                    smallestXDistance = xDistance;
                    smallestYDistance = yDistance;
                    continue;
                }
                if(parkingLots[j][1] < parkingLots[smallestIndex][1]
                && parkingLots[j][0] == parkingLots[smallestIndex][0]) {
                    smallestIndex = j;
                    smallestXDistance = xDistance;
                    smallestYDistance = yDistance;
                    continue;
                }
            }
        }
        //printf("index: %d\n", smallestIndex);
        lotCapacity[smallestIndex][0]++;
    }
 
 
    //final results of all lots
    for(int i = 0; i < nLots; i++) printf("%d\n", lotCapacity[i][0]);
 
}
 
int distance(int a, int b) {
    if(a > b) return a - b;
    return b - a;
}
