#include "book.h"
#include "date.h"
#include <stdbool.h>
#include <assert.h>
#include <math.h>
 
bool leapYear(int year) {
    if(year %4 != 0 || (year % 100 == 0 && year % 400 != 0))
        return false;
 
    return true;
}
 
int daysInMonth(int year, int month) {
    assert(month > 0 && month < 13);
 
    switch(month) {
        case 2: return leapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
    }
    return 31;
}
 
int maxAllowedTime(struct Book book) {
    switch(book.type) {
        case NOVEL:        return 90;
        case COMICS:    return 10;
        case MANUAL:    return 100;
        case TEXTBOOK:    return 5;
    }
    return -1;
}
 
int elapsed(struct Date date_borrowed, struct Date date_returned) {
 
    int currYear = date_borrowed.year;
    int currMonth = date_borrowed.month;
    int currDay = date_borrowed.day;
    int daysElapsed = 1;
 
    //first calculate if year of borrow and return is the same
    //if the same, just calculate elapsed time
 
    if(currYear == date_returned.year) {
        if(currMonth == date_returned.month) {
            daysElapsed += date_returned.day - date_borrowed.day;
            return daysElapsed;
        }
 
        daysElapsed += daysInMonth(currYear, currMonth) - currDay;
        while(++currMonth < date_returned.month) {
            daysElapsed += daysInMonth(currYear, currMonth);
        }
        daysElapsed += date_returned.day;
        return daysElapsed;
    } else {
        daysElapsed += daysInMonth(currYear, currMonth) - currDay;
        currMonth++;
        while(currYear < date_returned.year) {
            while(currMonth < 13) {
                daysElapsed += daysInMonth(currYear, currMonth);
                currMonth++;
            }
            currMonth = 1;
            currYear++;
        }
        while(currMonth < date_returned.month) {
            daysElapsed += daysInMonth(currYear, currMonth);
            currMonth++;
        }
        daysElapsed += date_returned.day;
        return daysElapsed;
    }
    return -1;
}
 
static int compute_dist(unsigned int n) {
    int a = __builtin_ffs(n) - 1;
    int b = __builtin_ffs(n ^ (1LU<<a)) - 1;
    return b - a - 1;
}
 
int importImportance(unsigned int decimal) {
    int power = 0;
    int binary = 0;
 
    int prevLoc = -1;
 
    while(pow(2, ++power) <= decimal);
 
    for(int i = power; i >= 0 && decimal > 0; i--) {
        if(decimal >= pow(2, i)) {
            if(prevLoc != -1) return (prevLoc - i) - 1;
            decimal -= pow(2, i);
            prevLoc = i;
        }
    }
    return 0;
}
 
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
 
    unsigned int maxDays = maxAllowedTime(book);
    unsigned int daysElapsed = elapsed(date_borrowed, date_returned);
#ifdef DEBUGDAYS
    printf("Days elapsed: %d\n", daysElapsed);
#endif
 
    int daysOverdue = daysElapsed - maxDays;
    if(daysOverdue <= 0) return 0;
 
    unsigned int importance = compute_dist(book.importance);
#ifdef DEBUGIMPORTANCE
    printf("Importance: %d\n", importance);
#endif
 
    return daysOverdue * importance;
}
