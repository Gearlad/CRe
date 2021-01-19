#include <stdio.h>
 
int linearDistance(int a, int b);
int absolute(int a);
 
main() {
    int Ax, Bx, Cx, Ay, By, Cy;
    scanf("%d%d%d%d%d%d", &Ax, &Ay, &Bx, &By, &Cx, &Cy);
 
    int Dx = Cx + linearDistance(Bx, Ax);
    int Dy = By + linearDistance(Cy, Ay);
 
    int Ex = Cx - linearDistance(Bx, Ax);
    int Ey = Ay + linearDistance(Cy, By);
 
    int Fx = Ax + linearDistance(Bx, Cx);
    int Fy = By - linearDistance(Cy, Ay);
 
    printf("%d\n%d\n%d\n%d\n%d\n%d", Dx, Dy, Ex, Ey, Fx, Fy);
}
 
int absolute(int a) {
    return a < 0 ? -a : a;
}
 
int linearDistance(int a, int b) {
    return a - b;
}
