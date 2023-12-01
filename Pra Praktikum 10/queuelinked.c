#include "queuelinked.h"
#include <stdio.h>
#include <stdlib.h>

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(Queue q) {
    return ADDR_HEAD(q) == NULL && ADDR_TAIL(q) == NULL;
}

int length(Queue q) {
    if(isEmpty(q)){
        return 0;
    }
    else{
        Address p = ADDR_HEAD(q);
        int count = 1;
        while(p != ADDR_TAIL(q)){
            count++;
            p = p->next;
        }
        return count;
    }
}

void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NULL;
    ADDR_TAIL(*q) = NULL;
}

void DisplayQueue(Queue q) {
    Address p = ADDR_HEAD(q);
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

void enqueue(Queue *q, ElType x) {
    Address p;
    p = newNode(x);
    if(p != NULL){
        if(isEmpty(*q)){
            ADDR_HEAD(*q) = p;
        }
        else{
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}

void dequeue(Queue *q, ElType *x) {
    Address p;
    *x = HEAD(*q);
    p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if(ADDR_HEAD(*q) == NULL){
        ADDR_TAIL(*q) = NULL;
    }
    NEXT(p) = NULL;
    free(p);
}
