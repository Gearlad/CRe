#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
#define MAXN 10000
 
typedef struct expense {
    int year, month, day, amt;
    char category[32];
} exp;
 
exp e[MAXN];
 
int match(exp a, exp b) {
    return (a.year == b.year)
        && (a.month == b.month)
        && (a.day == b.day)
        && (!strcmp(a.category, b.category));
}
 
int cmp(const void * a, const void * b) {
    int ay = ((exp *)a)->year;
    int am = ((exp *)a)->month;
    int ad = ((exp *)a)->day;
    char ac[32];
    strcpy(ac, ((exp *)a)->category);
 
    int by = ((exp *)b)->year;
    int bm = ((exp *)b)->month;
    int bd = ((exp *)b)->day;
    char bc[32];
    strcpy(bc, ((exp *)b)->category);
 
    return !((ay < by) ||
        ((ay == by) && (am < bm)) ||
        ((ay == by) && (am == bm) && (ad < bd)) ||
        ((ay == by) && (am == bm) && (ad == bd) && strcmp(ac, bc) < 0));
}
 
int main(void) {
    int n = 0;
 
 
    // scan all data
    char a[32];
    //printf("%d", n);
 
 
    while(scanf("%d %d %d %s %d", &(e[n].year), &(e[n].month),
        &(e[n].day), e[n].category, &(e[n].amt)) == 5) { n++; }
 
    qsort(e, n, sizeof(exp), cmp);
 
    for(int i = 0; i < n; i++) {
        if(i == n-1) {
            printf("%d %d %d %s %d\n", e[i].year, e[i].month,
            e[i].day, e[i].category, e[i].amt);
            break;
        }
        int j = i+1;
        int sumAmt = e[i].amt;
        // find items of same date and category
        while(match(e[i], e[j])) {
            sumAmt += e[j].amt;
            j++;
        }
 
        if(j > i+1) {
            printf("%d %d %d %s %d\n", e[i].year, e[i].month,
                e[i].day, e[i].category, sumAmt);
            i = j-1;
        } else {
            printf("%d %d %d %s %d\n", e[i].year, e[i].month,
                e[i].day, e[i].category, e[i].amt);
        }
    }
 
    return 0;
}
