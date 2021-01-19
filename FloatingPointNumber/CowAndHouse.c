#define PI 3.1415926
 
#include <stdio.h>
 
 
 
int main() {
 
    double a, b, c;
 
    scanf("%lf%lf%lf", &a, &b, &c);
 
 
 
    double areaCircle = PI * c * c;
 
    double grazeBottom = areaCircle * 0.75;
    double grazeLeft = b > c ? 0 : (c-b) * (c-b) * PI * .25;
    double grazeRight = a > c ? 0 : (c-a) * (c-a) * PI * .25;
    double grazeArea = grazeBottom + grazeLeft + grazeRight;
 
    printf("%f\n", grazeArea);
 
 
    return 0;
}
