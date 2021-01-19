#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main(void) {
    double a, b, c;
    while(scanf("%lf %lf %lf", &a, &b, &c) == 3) {
        //x = (-b ± sqrt(b^2-4ac))/2a
        double x1 = (-b + sqrt(pow(b, 2)-(4*a*c)))/(2*a);
        double x2 = (-b - sqrt(pow(b, 2)-(4*a*c)))/(2*a);
 
        printf("%.20lf %.20lf\n", (x1 < x2 ? x1 : x2), (x1 > x2 ? x1 : x2));
    }
 
    return 0;
}
