#include "employee.h"
 
int relation(Employee *employee1, Employee *employee2) {
    Employee *curr1 = employee1;
    Employee *curr2 = employee2;
 
    while(curr1 != curr1->boss) {
        if(curr1 == employee2) return 1;
        curr1 = curr1->boss;
    }
    if(curr1 == employee2) return 1;
 
    while(curr2 != curr2->boss) {
        if(curr2 == employee1) return 2;
        curr2 = curr2->boss;
    }
    if(curr2 == employee1) return 2;
 
    if(curr1 == curr2) return 3;
    return 4;
}
