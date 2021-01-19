#include <stdio.h>
 
int sizeArr;
int arr[20];
int sumArr[1024] = {};
 
 
 
void calcSums(int ind, int sum, int arr[]) {
    if(ind == sizeArr) {
        sumArr[sum]++;
        return;
    }
    calcSums(ind+1, sum, arr);
    calcSums(ind+1, sum+arr[ind], arr);
}
 
 
 
int main(void) {
    scanf("%d", &sizeArr);
 
    for(int i = 0; i < sizeArr; i++) {
        scanf("%d", &arr[i]);
    }
 
    calcSums(0, 0, arr);
 
    int k;
    while(scanf("%d", &k) != EOF) {
        printf("%d\n", sumArr[k]);
    }
 
 
    return 0;
}
