#include <stdio.h>
 
main() {
    int specialPrize[3][8];
    int firstPrize[3][8];
    int total = 0;
 
    for(int i = 0; i < 3; i++) {
        int special;
        scanf("%d", &special);
        for(int j = 7; j >= 0; j--) {
            specialPrize[i][j] = special % 10;
            special /= 10;
        }
    }
 
    //print special prize
    /*for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d", specialPrize[i][j]);
        }
        printf("\n");
    }*/
 
    for(int i = 0; i < 3; i++) {
        int first;
        scanf("%d", &first);
        for(int j = 7; j >= 0; j--) {
            firstPrize[i][j] = first % 10;
            first /= 10;
        }
    }
 
    /*for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%d", firstPrize[i][j]);
        }
        printf("\n");
    }*/
 
    int lottoNo;
    int lottoArr[8];
 
    while(scanf("%d", &lottoNo) != EOF) {
        for(int i = 7; i >= 0; i--) {
            lottoArr[i] = lottoNo % 10;
            lottoNo /= 10;
        }
 
        //check number of matching digits from back to front (special prize)
        int matchCount = 0;
 
        for(int i = 0; i < 3; i++) {
            if(matchCount == 8) break;
            matchCount = 0;
            for(int j = 7; j >= 0; j--) {
                if(lottoArr[j] == specialPrize[i][j]) matchCount++;
            }
        }
 
        if(matchCount == 8) total += 2000000;
 
        //first prize
        matchCount = 0;
        for(int i = 0; i < 3; i++) {
            if(matchCount >= 3) break;
            matchCount = 0;
            for(int j = 7; j >= 0; j--) {
                if(lottoArr[j] == firstPrize[i][j]) matchCount++;
                else break;
            }
        }
 
        switch(matchCount) {
            case 3:
                total += 200;
                break;
            case 4:
                total += 1000;
                break;
            case 5:
                total += 4000;
                break;
            case 6:
                total += 10000;
                break;
            case 7:
                total += 40000;
                break;
            case 8:
                total += 200000;
                break;
            }
 
        //this program is bugging me, hehehehehe
        //get it?
    }
 
    printf("%d", total);
    return 0;
}
