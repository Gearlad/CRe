#include <stdio.h>
 
int gcfCalc(int x, int y);
int lcmCalc(int x, int y);
 
int output = 0;
 
main() {
    /*   b      f
        a- (d) e-
         c      g
    */
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);
 
    //first convert to improper fraction
 
    int imp = a >= 0 ? (a * c) + b : (a * c) - b;
    int imp2 = e >= 0 ? (e * g) + f : (e * g) - f;
 
    //now combine
 
    // printf("%d/%d\n%d/%d\n", imp, c, imp2, g);
    int den = 0;
 
    //printf("%d %d/%d --%d-- %d %d/%d\n", a, b, c, d, e, f, g);
    switch(d) {
        case 0: //addition
            den = lcmCalc(c, g);
            imp *= (den / c);
            imp2 *= (den / g);
            //printf("%d/%d\n", imp, den);
            //printf("%d/%d\n", imp2, den);
            imp += imp2;
            break;
 
        case 1: //subtraction
            den = lcmCalc(c, g);
            imp *= (den / c);
            imp2 *= (den / g);
            //printf("%d/%d\n", imp, den);
            //printf("%d/%d\n", imp2, den);
            imp -= imp2;
            break;
        case 2: //multiplication
            imp *= imp2;
            den = c * g;
            break;
        case 3: //division
            imp *= g;
            den = c * imp2;
 
            //printf("(%d/%d)/(%d/%d)\n", imp, c, imp2, g);
 
            break;
    }
    //numerator of mixed number
 
    output = imp / den;
    int num = imp % den;
    //printf("num and den: %d/%d\n", num, den);
 
    int numMult = (num < 0) ? -1 : 1;
    int denMult = (den < 0) ? -1 : 1;
 
    //printf("%d mult %d\n", numMult, denMult);
 
    num *= numMult;
    den *= denMult;
 
    int gcfFinal = gcfCalc(num, den);
    //printf("gcf: %d\n", gcf1);
 
    num /= gcfFinal;
    den /= gcfFinal;
 
    if(num == 0) den = 1;
 
    printf("%d\n%d\n%d\n", output, num, den);
 
}
 
int gcfCalc(int x, int y) {
    if(x == 0) return y;
 
    while(y != 0) {
        if(x > y) {
            x -= y;
        } else {
            y -= x;
        }
    }
 
    return x;
}
 
int lcmCalc(int x, int y) {
    return (x * y) / gcfCalc(x, y);
}
