#include <stdio.h>
 
main() {
    //given total number of animals 's', total number of feet 'f', and total number of tails 't'
    //chicken: 2 feet, 1 tails
    //rabbits: 4 feet, 1 tails
    //crabs: 8 feet, 0 tails
    //calculate number of chickens, rabbits, and crabs
 
    int s, f, t;
    int chicken, rabbit, crab;
 
    scanf("%d%d%d", &s, &f, &t);
 
    crab = s - t;
    s -= crab;
    f -= (crab * 8);
 
    //chicken + rabbit = s
    //2*chicken + 2 * rabbit = 2s
    //2*chicken + 4 * rabbit = f;
    //2 * rabbit = f - s
    //rabbit = (f-s)/2
 
    rabbit = (f-2*s)/2;
    s -= rabbit;
 
    chicken = s;
 
    printf("%d\n%d\n%d", chicken, rabbit, crab);
}