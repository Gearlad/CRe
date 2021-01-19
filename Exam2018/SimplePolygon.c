#include <stdio.h>
main() {
    int ax,ay,bx,by,cx,cy,dx,dy;
    scanf("%d%d%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy);
 
    if(ax!=0) {
        int diff=ax>0? ax : -ax;
        ax+=diff;
        bx+=diff;
        cx+=diff;
        dx+=diff;
    }
    if(ay != 0) {
        int diff=ay>0 ? ay : -ay;
        ay+=diff;
        by+=diff;
        cy+=diff;
        dy+=diff;
    }
    int area=(cx-ax)*(cy-ay) - ((cx-bx)*(by-ay) + (dx-ax)*(cy-dy));
    int perimeter=(bx-ax)+(by-ay)+(cx-bx)+(cy-by)+(cx-dx)+(cy-dy)+(dx-ax)+(dy-ay);
    printf("%d\n%d\n", perimeter, area);
    return 0;
}
