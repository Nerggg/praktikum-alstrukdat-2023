#include <stdio.h>
#include "stacklinked.h"

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Stack i) {
    return ADDR_TOP(i) == NULL;
}

int length(Stack s) {
    int i = 0;
    int temp = 0;
    while(!isEmpty(s)) {
        pop(&s, &temp);
        i += 1;
    }
    return i;
}

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NULL;
}

void DisplayStack(Stack s) {
    Address p = ADDR_TOP(s);
    printf("[");
    while(p != NULL){
        if(p->next == NULL){
            printf("%i", p->info);
        }
        else{
            printf("%i,", p->info);
        }
        p = p->next;
    }
    printf("]");
}

void push(Stack *s, ElType x) {
    Address p;
    p = newNode(x);
    if(p != NULL){
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}

void pop(Stack *s, ElType *x) {
    Address p;
    *x = TOP(*s);
    p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NULL;
    free(p);
}
