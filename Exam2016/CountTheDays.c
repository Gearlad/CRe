#include <stdio.h>
#include <stdbool.h>
 
//#define DEBUG 0
 
enum day { MON, TUE, WED, THU, FRI, SAT, SUN };
 
bool leap_year(int year) {
    return (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0));
}
 
int days_in_month(int month, bool leap) {
    switch(month) {
        case 1: return 31;
        case 2: return leap ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
    }
    return -1;
}
 
void count_day(int year, int day, int month, int results[7]) {
#ifdef DEBUG
    printf("%d %d %d\n", year, month, day);
#endif
 
    bool leap = leap_year(year);
#ifdef DEBUG
    printf("leap: %d\n", leap);
#endif
 
    int numDays = 0;
    // month 3
 
    for(int i = 1; i < month; i++) {
        numDays += days_in_month(i, leap);
    }
 
#ifdef DEBUG
    printf("numDays: %d\n", numDays);
#endif
 
    int currDay = (day + numDays) % 7;
 
#ifdef DEBUG
    printf("currDay: %d\n", currDay);
#endif
 
    int daysFinalMonth = days_in_month(month, leap);
    for(int i = 1; i <= daysFinalMonth; i++) {
        results[currDay]++;
        currDay++;
        currDay %= 7;
    }
#ifdef DEBUG
    printf("\n");
#endif
}
