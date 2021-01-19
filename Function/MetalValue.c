#include "value.h"
/*#include <stdio.h>
 
int value(int type, int width, int height, int length);
 
main() {
    value(79, 0, 8, 2);
    return 0;
}*/
 
int value(int type, int width, int height, int length) {
 
    int unit = 0;
 
    switch(type) {
        case 79: //gold
            unit = 30;
            break;
        case 47: //silver
            unit = 10;
            break;
        case 29: //copper
            unit = 4;
            break;
        case 82: //lead
            unit = 5;
            break;
        case 26: //iron
            unit = 3;
            break;
        case 22: //titanium
            unit = 9;
            break;
        default:
#ifdef DEBUG
                printf("-1");
#endif
            return -1;
    }
 
    if(width <= 0 || height <= 0 || length <= 0) {
#ifdef DEBUG
    printf("-2");
#endif
        return -2;
    }
 
    //calculate dimensions gcf
    int num1 = width, num2 = height, num3 = length;
 
    while(num1 != num2) {
        if(num1 > num2) num1 -= num2;
        else num2 -= num1;
    }
 
    while(num1 != num3) {
        if(num1 > num3) num1 -= num3;
        else num3 -= num1;
    }
 
#ifdef DEBUG
    printf("gcf: %d\n", num1);
#endif
 
    //divide total volume by gcf for number of cubes
    //output = number cubes * cube volume^2 * unit price
 
    int volume = width * height * length;
    int cubeVolume = num1 * num1 * num1;
    int cubeCount = volume / cubeVolume;
#ifdef DEBUG
    printf("cubes: %d\n", cubeCount);
#endif
    int output = cubeCount * (cubeVolume * cubeVolume) * unit;
 
#ifdef DEBUG
    printf("%d", output);
#endif
    return output;
}
