#include <stdio.h>
 
main() {
    int width, height;
    scanf("%d%d", &width, &height);
 
    int currentX = 0;
    int currentY = 0;
 
    int instruction;
 
    printf("0\n0\n");
 
    while(scanf("%d", &instruction) != EOF) {
        int addedX = 0, addedY = 0;
        switch(instruction % 5) {
            case 0: continue;
            case 1:
                addedX += instruction;
                break;
            case 2:
                addedX += -instruction;
                break;
            case 3:
                addedY += instruction;
                break;
            case 4:
                addedY += -instruction;
                break;
        }
 
        if(currentX + addedX >= width || currentX + addedX < 0) continue;
        if(currentY + addedY >= height || currentY + addedY < 0) continue;
 
        currentX += addedX;
        currentY += addedY;
 
        printf("%d\n%d\n", currentX, currentY);
    }
 
    return 0;
 
}
