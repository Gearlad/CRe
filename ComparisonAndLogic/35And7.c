#include <stdio.h>
 
main()
{
    int x;
    scanf("%d", &x);
 
    int y = ((x % 3) == 0 && (x % 5 == 0)) && !(x % 7 == 0);
    if(y == 1)
        y = 0;
    else
        y = 1;
    printf("%d", y);
}
