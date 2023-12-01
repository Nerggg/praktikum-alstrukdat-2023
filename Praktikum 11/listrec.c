#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listrec.h"

Address newNode(ElType x) {
    Address p = (Address) malloc (sizeof(Node));
    if (p != NIL) {
        INFO(p) = x;
        NEXT(p) = NIL;
    }
}

boolean isEmpty(List l) {
    return l == NIL;
}

boolean isOneElmt(List l) {
    return (!isEmpty(l) && NEXT(l) == NIL);
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p == NULL) {
        return l;
    } else {
        NEXT(p) = l;
        return p;
    }
}

List konsb(List l, ElType e) {
    if (isEmpty(l)) {
        return newNode(e);
    } else {
        NEXT(l) = konsb(tail(l), e);
        return l;
    }
}

List copy(List l) {
    if (isEmpty(l)) {
        return l;
    } else {
        return konso(copy(tail(l)), head(l));
    } 
}
 
List concat(List l1, List l2) {
    if (isEmpty(l1)) {
        return copy(l2);
    } else {
        return konso(concat(tail(l1), l2), head(l1));
    }
}

int length(List l) {
    if (isEmpty(l)) {
        return 0;
    } else {
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    } else if (INFO(l) == x) {
        return true;
    } else {
        return isMember(tail(l), x);
    }
}

void displayList(List l) {
    if (!isEmpty(l)) {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

List insertAt(List l, ElType e, int idx) {
    if (!idx) {
        return konso(l, e);
    } else {
        return konso(insertAt(tail(l), e, idx - 1), head(l));
    }
}

List deleteFirst(List l) {
    return tail(l);
}

List deleteAt(List l, int idx) {
    if (!idx) {
        return deleteFirst(l);
    } else {
        return konso(deleteAt(tail(l), idx - 1), head(l));
    }
}

List deleteLast(List l) {
    return deleteAt(l, length(l) - 1);
}

List inverseList (List l) {
    if (isOneElmt(l)) {
        return l;
    } else {
        return konsb(inverseList(tail(l)), head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2) {
    if (!isEmpty(l)) {
        if (head(l) >= 0) {
            *l1 = konsb(*l1, head(l));
        } else {
            *l2 = konsb(*l2, head(l));
        }
        splitPosNeg(tail(l), l1, l2);
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2) {
    if (!isEmpty(l)) {
        if (head(l) < x) {
            *l1 = konsb(*l1, head(l));
        } else {
            *l2 = konsb(*l2, head(l));
        }
        splitOnX(tail(l), x, l1, l2);
    }
}

List removeDuplicate(List l, List unique) {
    if (isEmpty(l)) {
        return unique;
    } else if (isMember(unique, head(l))) {
        return removeDuplicate(tail(l), unique);
    } else {
        unique = konso(unique, head(l));
        return removeDuplicate(tail(l), unique);
    }
}