#include <stdio.h>
 
main() {
 
    char abcUpper[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z'};
 
    char abcLower[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
    'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z'};
 
    char charCount[26];
 
    for(int i = 0; i < 26; i++) {
        charCount[i] = 0;
    }
 
    char currentChar;
 
    //add method that scans all elements of char until '\n'
 
    while(1) {
        scanf("%c", ¤tChar);
        if(currentChar == '\n') break;
        for(int i = 0; i < 26; i++) {
            if(currentChar == abcUpper[i]
            || currentChar == abcLower[i]) {
                charCount[i]++;
            }
        }
    }
 
    for(int i = 0; i < 26; i++) {
        printf("%d\n", charCount[i]);
    }
 
    return 0;
}
