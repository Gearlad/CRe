#include <stdio.h>
 
int main(void) {
    int n;
    scanf("%d", &n);
 
    int prev, curr;
    int numSeg = 1;
 
    scanf("%d", &prev);
 
    for(int i = 1; i < n; i++) {
        scanf("%d", &curr);
 
        if(curr != prev)
            numSeg++;
        prev = curr;
    }
 
    printf("%d\n", numSeg);
}
