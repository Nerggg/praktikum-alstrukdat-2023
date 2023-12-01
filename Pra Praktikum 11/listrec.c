#include "listrec.h"
#include <stdlib.h>

Address newNode(ElType x) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = x;
        NEXT(p) = NULL;
    }
    return p;
}

boolean isEmpty(List l) {
    return (l == NULL);
}

boolean isOneElmt(List l) {
    return (!isEmpty(l) && isEmpty(tail(l)));
}

ElType head(List l) {
    return INFO(l);
}

List tail(List l) {
    return NEXT(l);
}

List konso(List l, ElType e) {
    Address p = newNode(e);
    if (p == NULL){
        return l;
    }
    else{
        NEXT(p) = l;
        return p;
    }
}

List konsb(List l, ElType e) {
	if (isEmpty(l)) {
	    return konso(l, e);
	} else {
	    return konso(konsb(tail(l), e), head(l));
	}
}

List copy(List l) {
    if(isEmpty(l)) {
        return NULL;
    }
    else {
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
    if(isEmpty(l)){
        return 0;
    }
    else{
        return 1 + length(tail(l));
    }
}

boolean isMember(List l, ElType x) {
    if (isEmpty(l)) {
        return false;
    }
    else {
        return (INFO(l) == x || isMember(tail(l), x));
    }
}

void displayList(List l) {
    if(!isEmpty(l)){
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}
