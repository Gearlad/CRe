#include <stdio.h>
 
main()
{
    int originalN, n, i;
    scanf("%d", &n);
    scanf("%d", &i);
 
    originalN = n;
 
    if(i != 1)
    {
        for(int a = 0; a < (i - 1); a++)
        {
            n *= originalN;
        }
    }
 
    printf("%d", n);
}
