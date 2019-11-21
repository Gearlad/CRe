#include <stdio.h>
 
main()
{
    int originalNum;
    int output[3];
    scanf("%d", &originalNum);
 
    for(int i = 0; i < 3; i++)
    {
        output[i] = originalNum % 10;
        originalNum /= 10;
    }
 
    printf("%d\n", output[2]);
    printf("%d\n", output[1]);
    printf("%d\n", output[0]);
}