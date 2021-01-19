#include <stdio.h>
#include <stdbool.h>
 
void printBool(bool* a);
int charToDig(char a);
 
main() {
    char c;
 
                    //2     //3    //5    //11
    bool divis[4] = {false, false, false, false};
 
    int currDigit;
 
    int digitCount = 0;
    int evenDigits = 0, oddDigits = 0;
 
    int tempTotal = 0;
 
    while(true) {
        scanf("%c", &c);
 
        if(c == '-') break;
        else if(c == '\n') {           
            divis[0] = currDigit % 2 == 0;
 
            if(evenDigits + oddDigits <= 3) {
                divis[1] = tempTotal % 3 == 0;
            } else {
                divis[1] = ((evenDigits + oddDigits) % 3 == 0);
            }
            divis[2] = (currDigit == 0 || currDigit == 5);
            divis[3] = (oddDigits - evenDigits) % 11 == 0;
 
            printBool(divis);
 
            digitCount = 0;
            currDigit = 0;
            evenDigits = 0;
            oddDigits = 0;
            tempTotal = 0;
 
            continue;
 
        }
 
        currDigit = charToDig(c);
 
        if(digitCount % 2 == 1) oddDigits += currDigit;
        else evenDigits += currDigit;
 
        digitCount++;
 
        if(digitCount > 4) tempTotal /= 10;
        tempTotal *= 10;
        tempTotal += currDigit;
        //printf("temp total: %d\n", tempTotal);
    }
 
    return 0;
}
 
 
void printBool(bool* a) {
 
 
    for(int i = 0; i < 4; i++) {
        if(i == 3) {
            if(a[i] == true) printf("yes\n");
            else printf("no\n");
            break;
        }
        if(a[i] == true) printf("yes ");
        else printf("no ");
        a[i] = false;
    }
}
 
int charToDig(char a) {
    char digits[10] = {'0', '1', '2', '3', '4', '5', '6',
    '7', '8', '9'};
 
    for(int i = 0; i < 10; i++) {
        if(a == digits[i]) return i;
    }
    return -1;
}
