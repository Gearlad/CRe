#include <stdio.h>
#include <stdbool.h>
 
int dayCount[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
 
//sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thursday = 4, friday = 5, saturday = 6
//incorrect month format = -1
//incorrect day format = -2
 
bool leapYear(int year);
int correctDate(int year, int month, int day, bool leap);
 
main() {
    //this scans the year and the day of the week that January 1st of that year is
    int year;
    int jan1;
    scanf("%d%d", &year, &jan1);
 
    int n;
    scanf("%d", &n);
 
    for(int i = 0; i < n; i++) {
        dayCount[1] = 28;
        int month;
        int day;
 
        scanf("%d%d", &month, &day);
 
        bool leap = leapYear(year);
        //printf(leap ? "true\n" : "false\n");
 
        int dateCorrect = correctDate(year, month, day, leap);
 
        if(dateCorrect != 0) printf("%d\n", dateCorrect);
        else {
            //normal program execution
            if(leap) dayCount[1]++;
 
            int daysBetween = -1;
 
            for(int i = 0; i < month-1; i++) {
                daysBetween += dayCount[i];
            }
 
            daysBetween += day;
 
            //printf("Days between: %d\n", daysBetween);
 
            int today = (daysBetween + jan1) % 7;
            printf("%d\n", today);
        }
    }
}
 
bool leapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) return true;
            else return false;
        }
        else return true;
    } else {
        return false;
    }
    return false;
}
 
int correctDate(int year, int month, int day, bool leap) {
    if(month < 1 || month > 12) return -1;
    if(leap == true && month == 2 && day > 29) return -2;
    if(leap == false && month == 2 && day > 28) return -2;
    if(day < 1) return -2;
    if((month == 1 || month == 3 || month == 5 || month == 7
    || month == 8 || month == 10 || month == 12) && day > 31) return -2;
 
    if((month == 9 || month == 4 || month == 6
    || month == 11) && day > 30) return -2;
 
    return 0;
}
