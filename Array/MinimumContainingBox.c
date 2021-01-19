#include <stdio.h>
 
main() {
    int x, y;
    int minX = 0;
    int minY = 0;
    int maxX = 0;
    int maxY = 0;
 
    scanf("%d%d", &x, &y);
    minX = x;
    minY = y;
    maxX = x;
    maxY = y;
 
    while(scanf("%d%d", &x, &y) != EOF) {
        if(x < minX) minX = x;
        if(y < minY) minY = y;       
 
        if(x > maxX) maxX = x;
        if(y > maxY) maxY = y;   
    }
 
    int diffX = minX > 0 ? minX : -minX;
    int diffY = maxY > 0 ? maxY : -maxY;
 
    minX += diffX;
    maxX += diffX;
    minY += diffY;
    maxY += diffY;
 
    int product = (maxX - minX) * (maxY - minY);
    printf("%d", product);
 
    return 0;
}
