#include <stdio.h>
#include "node.h"
 
#define MAXDEPTH 1000
 
void printArr(int path[], int len) {
    for(int i = 0; i < len; i++)
        printf("%d ", path[i]);
    printf("\n");
}
 
int isChild(struct node *node) {
    return (!node->left && !node->right);   
}
 
void calcPath(struct node *curr, int path[], int currLen) {
    if(!curr) // base case
        return;
    path[currLen] = curr->data;
    currLen++;
 
    if(isChild(curr)) {
        printArr(path, currLen);
    } else {
        calcPath(curr->left, path, currLen);
        calcPath(curr->right, path, currLen);
    }
}
 
void printPaths(struct node *node) {
    int path[MAXDEPTH];
    calcPath(node, path, 0);
}
 
void print_all_paths(struct node *root) {
    printPaths(root);
}
