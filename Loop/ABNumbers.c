#include <stdio.h>
 
main()
{
    int x, y;
    int A = 0, B = 0;
    int xArray[4];
    int yArray[4];
 
    scanf("%d", &x);
    scanf("%d", &y);
 
    for(int i = 0; i < 4; i++)
    {
        xArray[i] = x % 10;
        x /= 10;
 
        yArray[i] = y % 10;
        y /= 10;
    }
 
    for(int i = 0; i < 4; i++)
    {
        if(xArray[i] == yArray[i])
            A++;
 
        for(int j = 0; j < 4; j++)
        {
            if(xArray[i] == yArray[j] && i != j)
                B++;
        }
    }
 
    printf("%dA", A);
    printf("%dB", B);
 
    /*for(int i = 0; i < 4; i++)
    {
        printf("%d\n", xArray[i]);
    }*/
 
}
