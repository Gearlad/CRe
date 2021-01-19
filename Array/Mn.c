#include <stdio.h>
 
main()
{
    int N;
    scanf("%d", &N);
 
    int numbers[N];
 
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &numbers[i]);
    }
 
    int M;
    scanf("%d", &M);
 
    int remainders[N];
    //amount of numbers of a specific remainder
    int count[M];
    for(int i = 0; i < M; i++)
    {
        count[i] = 0;
    }
 
    for(int i = 0; i < N; i++)
    {
        remainders[i] = numbers[i] % M;
        count[remainders[i]]++;
    }
 
    for(int i = 0; i < M; i++)
    {
        printf("%d\n", count[i]);
    }
}
