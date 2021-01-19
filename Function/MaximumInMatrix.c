#include "max.h"
 
int max(int array[5][5])
{
    int i, j;
    int max = 0;
    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
        {
            if(array[i][j] > max)
            {
                max = array[i][j];
            }
        }
    }
    return max;
}
