#include "fill_array.h"
void fill_array(int *ptr[], int n) {
    int *begin = ptr[0], *end = ptr[n-1]+1;
    //end will be the ptr element after the last
    int m = 0;
    for(int *i = begin; i != end; i++)
        *i = -1, m++;
    for(int i = 0; i < n; i++)
        *(ptr[i]) = i;
    int lb = 0, rb = 1;
    while(begin[rb] == -1 && rb < m)
        rb++;
    for(int *i = begin; i != end; i++) {
        if(*i == -1)
            *i = begin[lb] + begin[rb];
        else if(begin+rb <= i) {
            lb = rb, rb++;
            while(rb < m && begin[rb] == -1)
                rb++;
        }
    }
    return;
}
