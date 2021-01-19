#include "computeGrade.h"
#include <stdio.h>
 
int max(int a, int b);
 
void computeGrade(Classes classes[2]) {
 
    double classAverage[2][18];
 
 
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 18; j++) {
            classAverage[i][j] = 0.0;
            for(int k = 0; k < classes[i].numStudent; k++) {
                classAverage[i][j] += classes[i].student[k].score[j].rawScore;
            }
            classAverage[i][j] /= classes[i].numStudent+0.0;
        }
    }
 
    for(int i = 0; i < 18; i++) {
        for(int j = 0; j < classes[0].numStudent; j++) {
            classes[0].student[j].score[i].scaledScore = -1;
        }
        for(int j = 0; j < classes[1].numStudent; j++) {
            classes[1].student[j].score[i].scaledScore = -1;
        }
    }
 
    for(int i = 0; i < 18; i++) {
        double ratio = 1.0;
 
        if(classAverage[0][i] > classAverage[1][i]) {
            ratio = classAverage[0][i] / classAverage[1][i];
            for(int j = 0; j < classes[1].numStudent; j++) {
                classes[1].student[j].score[i].scaledScore = classes[1].student[j].score[i].rawScore * ratio;
                if(classes[1].student[j].score[i].scaledScore > 100.0) {
                    classes[1].student[j].score[i].scaledScore = 100.0;
                }
            }
        }
 
        else {
            ratio = classAverage[1][i] / classAverage[0][i];
            for(int j = 0; j < classes[0].numStudent; j++) {
                classes[0].student[j].score[i].scaledScore = classes[0].student[j].score[i].rawScore * ratio;
                if(classes[0].student[j].score[i].scaledScore > 100.0) {
                    classes[0].student[j].score[i].scaledScore = 100.0;
                }
            }
        }
    }
 
 
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < classes[i].numStudent; j++) {
            classes[i].student[j].finalScore = 0.0;
            for(int k = 0; k < 18; k++) {
                double quizScore = classes[i].student[j].score[k].scaledScore == -1 ? classes[i].student[j].score[k].rawScore: classes[i].student[j].score[k].scaledScore;
                classes[i].student[j].finalScore += quizScore;
            }
            classes[i].student[j].finalScore *= .06;
            if(classes[i].student[j].finalScore > 100.0) classes[i].student[j].finalScore = 100.0;
            printf("%s %f\n", classes[i].student[j].id, classes[i].student[j].finalScore);
        }
    }
 
#ifdef DEBUG
    /*for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 18; j++) {
            printf("Class %d average quiz %d: %f\n", i, j, classAverage[i][j]);
        }
    }
 
    for(int i = 0; i < classes[0].numStudent; i++) {
        for(int j = 0; j < 18; j++) {
            printf("%f\n", classes[0].student[i].score[j].scaledScore);
        }
    }
 
    for(int i = 0; i < classes[1].numStudent; i++) {
        for(int j = 0; j < 18; j++) {
            printf("%f\n", classes[1].student[i].score[j].scaledScore);
        }
    }*/
 
    printf("\n");
#endif
 
}
 
int max(int a, int b) {
    if(a > b) return a;
    return b;
}
