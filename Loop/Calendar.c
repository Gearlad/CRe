#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
 
int daysInMonth(int year, int month, int day);
bool leapYear(int year);
void display(int day);
void invalid();
 
int days;
 
main() {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
 
    if(day < 0 || day > 7) invalid();
 
    daysInMonth(year, month, day);
    display(day);
 
    return 0;
}
 
void invalid() {
    printf("invalid");
    exit(0);
}
 
bool leapYear(int year) {
    if(year % 400 == 0) return true;
    if(year % 4 == 0 && year % 100 != 0) return true;
    else return false;
}
 
int daysInMonth(int year, int month, int day) {
    bool leap = leapYear(year);
 
    switch(month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        days = 31;
        break;
    case 4: case 6: case 9: case 11:
        days = 30;
        break;
    case 2:
        days = 28;
        if(leap) days++;
        break;
    default:
        invalid();
    }
 
 
}
 
void display(int day) {
    //int rows = ((days + day) / 7;
    int rowSwitcher = day;
 
    printf(" Su Mo Tu We Th Fr Sa\n");
    printf("=====================\n");
    for(int i = 0; i < day; i++) {
        printf("   ");
    }
    for(int i = 1; i <= days; i++) {
        if(rowSwitcher > 6) {
            rowSwitcher = 0;
            printf("\n");
        }
        printf("%3d", i);
        rowSwitcher++;
    }
    printf("\n");
 
    printf("=====================");
}
