#include <stdio.h>
#include <string.h>
 
#define MAXN 32
 
const char *commands[4] = {"earns", "spends", "gives", "becomes"};
 
int N;
 
typedef struct Account {
    char name[MAXN];
    int bal;
} account;
 
account accounts[MAXN];
 
int findUser(char username[]) {
    for(int i = 0; i < N; i++) {
        if(!strcmp(username, accounts[i].name))
            //printf("%s %s\n", username, accounts[i].name);
            return i;
    }
    return -1;
}
 
int command(char c[]) {
    for(int i = 0; i < 4; i++) {
        if(strstr(c, commands[i]) != NULL)
            return i;
    }
    return -1;
}
 
void printArr() {
    for(int i = 0; i < N; i++) {
        printf("%s %d\n", accounts[i].name, accounts[i].bal);
    }
}
 
int main() {
    scanf("%d", &N);
 
    for(int i = 0; i < N; i++) {
        scanf("%s %d", accounts[i].name, &(accounts[i].bal));
    }
 
    char usr[32], usr2[32], cmd[32];
    int amt;
 
    while(scanf("%s %s", usr, cmd) != EOF) {
        int c = command(cmd);
        int usrInd = findUser(usr);
        int usrInd2 = 0;
 
        if(c == 2) {
            scanf("%s", usr2);
            usrInd2 = findUser(usr2);
            //printf("c: %d, usr1: %s, usr2: %s, amt: %d\n", c, accounts[usrInd].name, accounts[usrInd2].name, amt);
        } else {
            //printf("c: %d, usr1: %s, amt: %d\n", c, accounts[usrInd].name, amt);
        }
 
        scanf("%d", &amt);
 
        if(c == -1 || usrInd == -1 || usrInd2 == -1) continue;
 
        int temp;
        switch(c) {
            case 0: // earn
                accounts[usrInd].bal += amt;
                break;
            case 1: // spend
                if(accounts[usrInd].bal - amt < 0) continue;
                accounts[usrInd].bal -= amt;
                break;
            case 2: // give
                if(accounts[usrInd].bal - amt < 0) continue;
                accounts[usrInd].bal -= amt;
                accounts[usrInd2].bal += amt;
                break;
            case 3: // become
                if(amt < 0) continue;
                accounts[usrInd].bal = amt;
                break;
        }
 
    }
 
    printArr();
 
    return 0;
}
