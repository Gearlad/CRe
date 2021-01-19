#include <stdio.h>
#include <stdbool.h>
 
main() {
    int mapHeight, mapWidth;
    scanf("%d%d", &mapHeight, &mapWidth);
    int map[mapHeight][mapWidth];
 
    int tankLength, tankWidth;
    scanf("%d%d", &tankLength, &tankWidth);
    int tank[2] = {0, 0};
 
    int i, j;
    for(i = 0; i < mapHeight; i++) {
        for(j = 0; j < mapWidth; j++) {
            map[i][j] = 0;
        }
    }
 
    int obstacleCount;
    scanf("%d", &obstacleCount);
 
    for(i = 0; i < obstacleCount; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        map[y][x] = 2;
    }
 
    bool prev = false;
 
    int instruction;
    while(scanf("%d", &instruction) != EOF) {
#ifdef DEBUG
        printf("Instruction: %d\n", instruction);
#endif
        int testX = tank[0], testY = tank[1];
        switch(instruction) {
            case 0: //print map
                if(prev == true) printf("\n");
                for(i = 0; i < mapHeight; i++) {
                    for(j = 0; j < mapWidth; j++) {
                        if(i >= tank[1] && i < tank[1] + tankLength
                        && j >= tank[0] && j < tank[0] + tankWidth) {
                            printf("1");
                        }
                        else {
                            printf("%d", map[i][j]);
                        }
                    }
                    if(i < mapHeight-1) printf("\n");
                }
                prev = true;
                break;
            case 1: //x+1, y
                testX = tank[0] + 1;
                break;
            case 2: //x, y+1
                testY = tank[1] + 1;
                break;
            case 3: //x-1, y
                testX = tank[0] - 1;
                break;
            case 4: //x, y-1
                testY = tank[1] - 1;
                break;
            case 5: //x+1, y+1
                testX = tank[0] + 1;
                testY = tank[1] + 1;
                break;
        }
        //calculate if legal instruction
        //-> within boundaries
        //-> does not go over obstacle
 
        if(instruction != 0
        && testX >= 0 && testY >= 0
        && testX <= (mapWidth-tankWidth)
        && testY <= (mapHeight-tankLength)) {
            int obstaclesAhead = 0;
            //count number of obstacles
            for(i = testY; i < testY + tankLength; i++) {
                for(j = testX; j < testX + tankWidth; j++) {
                    if(map[i][j] == 2) obstaclesAhead++;
                }
            }
 
#ifdef DEBUG
            printf("Obstacles: %d\n", obstaclesAhead);
#endif
 
            //switching values
            if(obstaclesAhead < 2) {
                tank[0] = testX;
                tank[1] = testY;
                if(obstaclesAhead == 1) {
                    for(i = tank[1]; i < tank[1] + tankLength; i++) {
                        for(j = tank[0]; j < tank[0] + tankWidth; j++) {
                            map[i][j] = 0;
                        }
                    }
                }
#ifdef DEBUG
                printf("test x: %d, test y: %d\n", testX, testY);
                printf("tank x: %d, tank y: %d\n", tank[0], tank[1]);
#endif
            }
        }
 
#ifdef DEBUG
        for(i = 0; i < mapHeight; i++) {
            for(j = 0; j < mapWidth; j++) {
                printf("%d", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
 
#endif
 
    }
 
    return 0;
}
