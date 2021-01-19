#include <stdio.h>
 
main()
{
    int n;
    scanf("%d", &n);
    int numbers[n];
 
    for(int a = 0; a < n; a++)
    {
        scanf("%d", &numbers[a]);
    }
 
    int oddNumbers[n];
    int evenNumbers[n];
 
 
    int evenCounter = 0;
    int oddCounter = 0;
 
    for(int b = 0; b < n; b++)
    {
        if(numbers[b] % 2 != 0)
        {
            oddNumbers[oddCounter] = numbers[b];
            oddCounter++;
        }
        else
        {
            evenNumbers[evenCounter] = numbers[b];
            evenCounter++;
        }
    }
 
    for(int c = 0; c < oddCounter; c++)
    {
        if(c == oddCounter - 1)
        {
            printf("%d\n", oddNumbers[c]);
        }
        else
        {
            printf("%d ", oddNumbers[c]);
        }
    }
 
    for(int d = 0; d < evenCounter; d++)
    {
        if(d == evenCounter - 1)
        {
            printf("%d", evenNumbers[d]);
        }
        else
        {
            printf("%d ", evenNumbers[d]);
        }
    }
 
 
}
