#include <stdio.h>
 
int numbers[32];
int N, M, k;
 
int sol(int x, int p, int sum) {
    if(x == N) // all numbers iterated
        return sum <= M && p >= k;
    int ret = sol(x+1, p+1, sum + numbers[x]); // choose element n
    ret += sol(x+1, p, sum); // don't choose element n
    return ret;
}
 
int main(void) {
    scanf("%d%d%d", &k, &N, &M);
 
    for(int i = 0; i < N; i++) {
        scanf("%d", &(numbers[i]));
    }
 
    int res = sol(0, 0, 0);
    printf("%d\n", res);
 
    return 0;
}
