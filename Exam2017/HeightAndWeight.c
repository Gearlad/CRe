#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
 
#define MAXN 100001
 
double BMICalc(int height, int weight) {
    return ((double)weight / pow((double)height/100.0, 2));
}
 
typedef struct student {
    char name[64];
    int height, weight;
    double BMI;
} student;
 
student s[MAXN];
 
int cmp(const void * a, const void * b) {
    student *aS = (student *)a;
    student *bS = (student *)b;
 
    return((aS->BMI > bS->BMI) ||
        ((aS->BMI == bS->BMI) && (aS->weight > bS->weight)) ||
        ((aS->BMI == bS->BMI) && (aS->weight == bS->weight) && (aS->height > bS->height)) ||
        ((aS->BMI == bS->BMI) && (aS->weight == bS->weight) && (aS->height == bS->height) && (strcmp(aS->name, bS->name) > 0)));
}
 
int main(void) {
    int N;
    scanf("%d", &N);
 
    for(int i = 0; i < N; i++) {
        scanf("%s %d %d", s[i].name, &s[i].height, &s[i].weight);
        s[i].BMI = BMICalc(s[i].height, s[i].weight);
    }
 
#ifdef DEBUG
    printf("\n\n\n\n\n");
    for(int i = 0; i < N; i++) {
        printf("%s %d %d %lf\n", s[i].name, s[i].height, s[i].weight, s[i].BMI);
    }
    printf("\n\n\n\n\n");
#endif
 
    qsort(s, N, sizeof(student), cmp);
 
    for(int i = 0; i < N; i++) {
        printf("%s %d %d\n", s[i].name, s[i].height, s[i].weight);
    }
 
}
