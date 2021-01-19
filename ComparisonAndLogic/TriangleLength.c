#include <stdio.h>
 
main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
 
    int final = ((a + b) > c) && ((a + c) > b) && ((b + c) > a);
    printf("%d", final);
}
