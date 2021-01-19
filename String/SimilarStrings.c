#include <strings.h>
#include <stdio.h>
#include <stdbool.h>
 
void swap(char a[], char b[]) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
 
int main(void) {
 
    int N;
    scanf("%d", &N);
 
    char a[80];
    char b[80] ;
 
    bool similar;
 
    for(int i = 0; i < N; i++) {
        similar = false;
        scanf("%s %s", a, b);
 
        if(strlen(a) == strlen(b)) {
            //case 3
            if(!strcmp(a, b)) {
                similar = true;
            }
 
            //case 1
            for(int i = 0; i < strlen(a)-1 && similar == false; i++) {
                char temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                if(!strcmp(a, b)) similar = true;
                else {
                    char temp = a[i];
                    a[i] = a[i+1];
                    a[i+1] = temp;
                }
#ifdef DEBUG
                printf("%s\n", a);
#endif
            }
        }
 
        else if(strlen(a) != strlen(b)) {
 
            if(strlen(b) > strlen(a)) {
                char temp[80];
                strcpy(temp, a);
                strcpy(a, b);
                strcpy(b, temp);
            }
 
            for(int i = 0; i < strlen(a) && similar == false; i++) {
                char c[80];
                int counter = 0;
                for(int j = 0; j < strlen(a); j++) {
                    if(j != i) {
                        c[counter] = a[j];
                        counter++;
                    }
                }
                c[counter] = '\0';
#ifdef DEBUG
                printf("%s\n", c);
#endif
                if(!strcmp(c, b)) similar = true;
            }
        }
 
 
 
        if(similar) printf("yes\n");
        else printf("no\n");
 
    }
 
 
    return 0;
}
