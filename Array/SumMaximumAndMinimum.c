#include <stdio.h> 
main() {
    int N, m;
 
    scanf("%d%d", &N, &m);
 
    int arr[N];
 
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
 
    /*for(int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }*/
 
    int sum, max, min;
 
    for(int i = 0; i < m; i++) {
        sum = 0;
        max = 0;
        min = 10000;
        for(int j = 0; j < N; j++) {
            if(arr[j] % m == i) {
                sum += arr[j];
                if(arr[j] > max) max = arr[j];
                if(arr[j] < min) min = arr[j];
            }
        }
        printf("%d %d %d\n", sum, max, min);
    }
 
    return 0;
}
