#include <stdio.h>
 
main() {
    //write a program that takes a, b, c, d, and e
    //calculate surface area
    //think of it as a prism with a, b, c as its length, width, and height
    //every side of it has a
 
    int a, b, c, d, e;
 
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
 
    int area = (a * b + a * c + b * c)*2;
 
    int face1 = ((c - 2 * e) * d * 2) + ((a - 2 * e) * d  * 2);
    //printf("%d\n", face1);
 
    int face2 = ((b - 2 * e) * d * 2) + ((c - 2 * e) * d  * 2);
    //printf("%d\n", face2);
 
    int face3 = ((b - 2 * e) * d * 2) + ((a - 2 * e) * d  * 2);
    //printf("%d\n", face3);
 
 
    area += ((face1 + face2 + face3) * 2);
    printf("%d\n", area);
 
    int volume = a * b * c;
 
    int volume1 = (c - 2 * e) * d * (a - 2 * e);
    //printf("%d\n", volume1);
    int volume2 = (b - 2 * e) * d * (c - 2 * e);
    int volume3 = (b - 2 * e) * d * (a - 2 * e);
 
    volume -= ((volume1 + volume2 + volume3)*2);
    printf("%d", volume);
}