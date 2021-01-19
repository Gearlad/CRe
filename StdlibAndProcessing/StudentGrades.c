#include <stdio.h>
 
#define MAXN 100000
 
int numToR(int g) {
    int r = -1;
    if(g >= 90 && g <= 100) { // A+
        r = 0;
    } else if(g >= 85 && g <= 89) { // A
        r = 1;
    } else if(g >= 80 && g <= 84) { // A-
        r = 2;
    } else if(g >= 77 && g <= 79) { // B+
        r = 3;
    } else if(g >= 73 && g <= 76) { // B
        r = 4;
    } else if(g >= 70 && g <= 72) { // B-
        r = 5;
    } else if(g >= 67 && g <= 69) { // C+
        r = 6;
    } else if(g >= 63 && g <= 66) { // C
        r = 7;
    } else if(g >= 60 && g <= 62) { // C-
        r = 8;
    } else { // F
        r = 9;
    }
    return r;
}
 
int main(void) {
    int count = 0;
    int grades[MAXN];
 
    while(scanf("%d", &(grades[count])) != EOF) {
        count++;
    }
 
#ifdef HUNDRED
    int total = 0;
    for(int i = 0; i < count; i++) {
        total += grades[i];
        printf("%d ", grades[i]);
    }
 
    double avg = ((double)total)/count;
    printf("%.1lf\n", avg);
#endif
 
#ifdef APLUS
    double avgRank = 0.0;
    double avgHunGrade = 0.0;
 
    for(int i = 0; i < count; i++) {
        int cur = numToR(grades[i]);
        char *out = NULL;
        switch(cur) {
            case 0:
                out = "A+";
                avgRank += 4.3;
                avgHunGrade += 95;
                break;
            case 1:
                out = "A";
                avgRank += 4.0;
                avgHunGrade += 87;
                break;
            case 2:
                out = "A-";
                avgRank += 3.7;
                avgHunGrade += 82;
                break;
            case 3:
                out = "B+";
                avgRank += 3.3;
                avgHunGrade += 78;
                break;
            case 4:
                out = "B";
                avgRank += 3.0;
                avgHunGrade += 75;
                break;
            case 5:
                out = "B-";
                avgRank += 2.7;
                avgHunGrade += 70;
                break;
            case 6:
                out = "C+";
                avgRank += 2.3;
                avgHunGrade += 68;
                break;
            case 7:
                out = "C";
                avgRank += 2.0;
                avgHunGrade += 65;
                break;
            case 8:
                out = "C-";
                avgRank += 1.7;
                avgHunGrade += 60;
                break;
            case 9:
                out = "F";
                //avgRank += 0.0;
                avgHunGrade += 50;
                break;
        }
        printf("%s ", out);
    }
    avgRank /= (double)count;
    printf("%.1lf ", avgRank);
 
    avgHunGrade /= (double)count;
    printf("%.1lf\n", avgHunGrade);
 
 
#endif
 
 
    return 0;
}
