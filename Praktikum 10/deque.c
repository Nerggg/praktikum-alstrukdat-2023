#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

Address newNode(ElType x) {
    Address p = (Address)malloc(sizeof(Node));
    if (p != NULL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
    return p;
}

boolean isEmpty(Deque q) {
    return (ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL);
}

int length(Deque q) {
    Address p = ADDR_HEAD(q);
    int count = 0;
    while (p != NIL) {
        count++;
        p = NEXT(p);
    }
    return count;
}

void CreateDeque(Deque *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}

void DisplayDeque(Deque q) {
    Address P = ADDR_HEAD(q);
    printf("[");
    while (P != NIL) {
        printf("%d", INFO(P));
        P = NEXT(P);
        if (P != NIL) {
            printf(",");
        }
    }
    printf("]");
}

void EnqueueHead(Deque *q, ElType x) {
    Address P = newNode(x);
    if (P != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = P;
            ADDR_TAIL(*q) = P;
        } else {
            NEXT(P) = ADDR_HEAD(*q);
            ADDR_HEAD(*q) = P;
        }
    }
}

void DequeueHead(Deque *q, ElType *x) {
    if (!isEmpty(*q)) {
        *x = INFO(ADDR_HEAD(*q));
        Address P = ADDR_HEAD(*q);
        ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
        free(P);

        if (ADDR_HEAD(*q) == NIL) {
            ADDR_TAIL(*q) = NIL;
        }
    }
}

void EnqueueTail(Deque *q, ElType x) {
    Address P = newNode(x);
    if (P != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = P;
            ADDR_TAIL(*q) = P;
        } else {
            NEXT(ADDR_TAIL(*q)) = P;
            ADDR_TAIL(*q) = P;
        }
    }
}

void DequeueTail(Deque *q, ElType *x) {
    if (length(*q) == 1) {
        *x = INFO(ADDR_TAIL(*q));
        ADDR_HEAD(*q) = NIL;
        ADDR_TAIL(*q) = NIL;
    } else if (!isEmpty(*q)) {
        *x = INFO(ADDR_TAIL(*q));
        Address P = ADDR_TAIL(*q);

        Address start = ADDR_HEAD(*q);
        while (NEXT(start) != P) {
            start = NEXT(start);
        }
        NEXT(start) = NIL;
        ADDR_TAIL(*q) = start;
        free(P);

        if (ADDR_HEAD(*q) == NIL) {
            ADDR_TAIL(*q) = NIL;
        }
    }
}