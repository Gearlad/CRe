#include <stdio.h>
 
main()
{
    int height, width, depth;
 
    scanf("%d", &height);
    scanf("%d", &width);
    scanf("%d", &depth);
 
    //2 × w × l + 2 × l × h + 2 × h × w
    int surfaceArea = (2 * width * depth) + (2 * depth * height) + (2 * height * width);
    int volume = height * width * depth;
 
    printf("%d\n", surfaceArea);
    printf("%d\n", volume);
}