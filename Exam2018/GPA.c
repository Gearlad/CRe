#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GPA_calculation.h"
 
double GPA_val(char score[]) {
    double ret = 0.0;
 
    switch(score[0]) {
        case 'A':
            ret = 4.0; break;
        case 'B':
            ret = 3.0; break;
        case 'C':
            ret = 2.0; break;
    }
 
    if(score[1] == '+') ret += .3;
    else if(score[1] == '-') ret -= .3;
 
    return ret;
}
 
int cmp(const void *x, const void *y) {
    struct Student *a = (struct Student *)x;
    struct Student *b = (struct Student *)y;
    if(a->GPA < b->GPA) return 1;
    else if(a->GPA > b->GPA) return -1;
    return 0;
}
 
void GPA_calculation(struct Student all_student[], int N) {
 
    int numPrizes = ((N-1)/20)+1;
    int indeces[N];
 
    for(int i = 0; i < N; i++) {
        all_student[i].GPA = 0.0;
        all_student[i].N_credit = 0;
 
        double temp_GPA;
 
        for(int j = 0; j < all_student[i].N_class; j++) {
            temp_GPA = GPA_val(all_student[i].all_class[j].score);
            temp_GPA *= all_student[i].all_class[j].academic_credit;
            all_student[i].GPA += temp_GPA;
            all_student[i].N_credit += all_student[i].all_class[j].academic_credit;
        }
 
        all_student[i].GPA /= all_student[i].N_credit;
    }
 
 
    qsort(all_student, N, sizeof(struct Student), cmp);
    int rank = 1;
    for(int i = 0; i < N; i++) {
        if(numPrizes <= 0) break;
        if(all_student[i].N_credit >= 15 && all_student[i].GPA >= 3.38) {
            printf("%d %s %f\n", rank, all_student[i].name, all_student[i].GPA);
        }
        rank++;
        numPrizes--;
    }
}
