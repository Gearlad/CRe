#include "node.h"
#include <stdio.h>
 
struct node *getNode(struct node *head, unsigned int i) {
    int size = 0;
    struct node *tmp = head;
 
    while(tmp) { tmp = tmp->next, size++; }
 
    int numIt = size-1-i;
    while(numIt--) {
        if(head == NULL) return NULL;
        head = head->next;
    }
 
    return head;
}
