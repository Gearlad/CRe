#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct {
    int id;
    char first_name[32];
    char last_name[32];
    int boss_id;
} employee;
 
employee A[32];
 
int n, m;
int parent[32];
 
void scanVal(employee *emp) {
    scanf("%s%s", emp->first_name, emp->last_name);
}
 
void assignParent() {
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
 
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(A[i].boss_id == A[j].id) {
                parent[i] = j;
            }
        }
    }
}
 
int nameToIndex(employee *emp) {
    for(int i = 0; i < n; i++) {
        if(!strcmp(emp->first_name, A[i].first_name)
            && !strcmp(emp->last_name, A[i].last_name))
            return i;
    }
    return -1;
}
 
int relationship(int indexOne, int indexTwo) {
    int currOne = parent[indexOne];
    int currTwo = parent[indexTwo];
 
    while(currOne != parent[currOne]) {
        if(currOne == indexTwo) return 0;
        currOne = parent[currOne];
    }
    if(currOne == indexTwo) return 0;
 
    while(currTwo != parent[currTwo]) {
        if(currTwo == indexOne) return 1;
        currTwo = parent[currTwo];
    }
    if(currTwo == indexOne) return 1;
    if(currOne == currTwo) return 2;
    return 3;
}
 
int main(void) {
 
    scanf("%d", &n);
 
    for(int i = 0; i < n; i++) {
        scanf("%d", &A[i].id);
        scanVal(&A[i]);
        scanf("%d", &A[i].boss_id);
    }
 
    assignParent();
 
    char out[4][32] = {"subordinate", "supervisor", "colleague", "unrelated"};
 
    employee one, two;
 
    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanVal(&one);
        scanVal(&two);
 
        int indexOne = nameToIndex(&one);
        int indexTwo = nameToIndex(&two);
 
        int output;
 
        if(indexOne == -1 || indexTwo == -1) {
            puts(out[3]);
        } else {
            puts(out[relationship(indexOne, indexTwo)]);
        }
    }
 
    return 0;
}
