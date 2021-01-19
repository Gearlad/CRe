#include <stdio.h>
 
int inches(int yards, int feet, int inches) {
    while(yards > 0) {
        yards--;
        feet += 3;
    }
    while(feet > 0) {
        feet--;
        inches += 12;
    }
    return inches;
}
void distribute(int length[3]) {
    while(length[2] >= 12) {
        length[2] -= 12;
        length[1]++;
        while(length[1] >= 3) {
            length[1] -= 3;
            length[0]++;
        }
    }
}
void init(int length[3]) {
    for(int i = 0; i < 3; i++)
        length[i] = 0;
}
void add(int length[3], int i) {
    length[2] += i;
    distribute(length);
}
void sum(int lengtha[3], int lengthb[3], int lengthc[3]) {
    lengthc[2] = inches(lengtha[0], lengtha[1], lengtha[2]) + inches(lengthb[0], lengthb[1], lengthb[2]);
    lengthc[1] = 0, lengthc[0] = 0;
    distribute(lengthc);
}
void diff(int lengtha[3], int lengthb[3], int lengthc[3]) {
    lengthc[2] = inches(lengtha[0], lengtha[1], lengtha[2]) - inches(lengthb[0], lengthb[1], lengthb[2]);
    lengthc[1] = 0, lengthc[0] = 0;
    distribute (lengthc);
}
