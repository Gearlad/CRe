#include "node.h"
#include <stdio.h>
 
struct node * merge(struct node *n1, struct node *n2) {
    if(n1 == NULL) return n2; // base case
    if(n2 == NULL) return n1; // base case
 
    if(n1->value < n2->value) {
        n1->next = merge(n1->next, n2);
        return n1;
    } else {
        n2->next = merge(n1, n2->next);
        return n2;
    }
}
