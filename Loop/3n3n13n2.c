#include <stdio.h>
 
main()
{
    int n;
    scanf("%d", &n);
 
    int numbers[n];
 
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }
 
    int remainders[3] = {0, 0, 0};
 
    for(int a = 0; a < n; a++)
    {
        int remainder = numbers[a] % 3;
        switch(remainder)
        {
            case 0:
                remainders[0]++;
                break;
            case 1:
                remainders[1]++;
                break;
            case 2:
                remainders[2]++;
                break;
        }
    }
    printf("%d %d %d", remainders[0], remainders[1], remainders[2]);
}
