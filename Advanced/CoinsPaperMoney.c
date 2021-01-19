#include <stdio.h>
 
int amt[7] = { 1000, 500, 100, 50, 10, 5, 1 };
 
 
int main(void) {
    int curr;
 
    while(scanf("%d", &curr) == 1) {
        int sum = 0;
 
        int val[7] = { 0, 0, 0, 0, 0, 0, 0};
 
        for(int i = 0; i < 7; i++) {
            while(sum + amt[i] <= curr) {
                sum += amt[i];
                val[i]++;
            }
        }
 
        for(int i = 0; i < 7; i++) {
            printf("%d", val[i]);
            if(i != 6) printf(" ");
        }
        printf("\n");
    }
 
    return 0;
}
