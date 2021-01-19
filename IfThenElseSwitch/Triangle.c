#include <stdio.h>
 
main() {
    int n;
    scanf("%d", &n);
 
    //isosceles, acute, obtuse, right
    //isosceles: one side equals the length of another side
    //acute: a^2+b^2>c^2
    //obtuse: a^2+b^2<c^2
    //right: a^2+b^2=c^2
 
    for(int i = 0; i < n; i++) {
        int x1, y1, x2, y2, x3, y3;
        scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
 
        //keep all sides in square form
        int side1 = 0;
        int side2 = 0;
        int side3 = 0;
 
        int xD;
        int yD;
 
        //side 1
        xD = 0;
        yD = 0;
        if(x1 > x2) xD = x1 - x2;
        else if(x2 > x1) xD = x2 - x1;
 
        if(y1 > y2) yD = y1 - y2;
        else if(y2 > y1) yD = y2 - y1;
 
        if(xD == 0) side1 = yD * yD;
        else if(yD == 0) side1 = xD * xD;
        else side1 = xD * xD + yD * yD;
 
        //side 2
        xD = 0;
        yD = 0;
        if(x2 > x3) xD = x2 - x3;
        else if(x3 > x2) xD = x3 - x2;
 
        if(y2 > y3) yD = y2 - y3;
        else if(y3 > y2) yD = y3 - y2;
 
        if(xD == 0) side2 = yD * yD;
        else if(yD == 0) side2 = xD * xD;
        else side2 = xD * xD + yD * yD;
 
        //side 3
        xD = 0;
        yD = 0;
        if(x3 > x1) xD = x3 - x1;
        else if(x1 > x3) xD = x1 - x3;
 
        if(y3 > y1) yD = y3 - y1;
        else if(y1 > y3) yD = y1 - y3;
 
        if(xD == 0) side3 = yD * yD;
        else if(yD == 0) side3 = xD * xD;
        else side3 = xD * xD + yD * yD;
 
        /*printf("side 1: %d\n", side1);
        printf("side 2: %d\n", side2);
        printf("side 3: %d\n", side3);*/
 
 
        //isosceles gets first priority
        if(side1 == side2 || side1 == side3 || side2 == side3) {
            printf("isosceles\n");
        } else {
            //assign sides to a, b, c
 
            int a = 0;
            int b = 0;
            int c = 0;
 
            if(side1 > side2 && side1 > side3) {
                c = side1;
                a = side2;
                b = side3;
            }
            else if(side2 > side1 && side2 > side3) {
                c = side2;
                a = side1;
                b = side3;
            }
            else if(side3 > side1 && side3 > side2) {
                c = side3;
                a = side1;
                b = side2;
            }
 
            /*printf("a: %d\n", a);
            printf("b: %d\n", b);
            printf("c: %d\n", c);*/
 
            if(a + b > c) {
                printf("acute\n");
            } else if(a + b < c) {
                printf("obtuse\n");
            } else printf("right\n");
        }
    }
}
