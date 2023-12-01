#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l) {
	return FIRST(l) == NULL;
}

void CreateList(List *l) {
	FIRST(*l) = NULL;
}

Address allocate(ElType val) {
	Address p = (Address) malloc(sizeof(ElmtList));
	if (p!=NULL) {
		INFO(p) = val;
		NEXT(p) = NULL;
	}
	return p;
}

void deallocate(Address P) {
	free(P);
}

Address search(List l, ElType val) {
	if(isEmpty(l)){
		return NULL;
	}
	else{
		Address p = FIRST(l);
		boolean found = false;
		while(p->next != FIRST(l) && !found){
			if(p->info == val){
				found = true;
			}
			else{
				p = p->next;
			}
		}
		if(p->info == val){
			found = true;
		}
		if(found){
			return p;
		}
		else{
			return NULL;
		}
	}
}

boolean addrSearch(List l, Address p) {
	Address q;
	if(isEmpty(l)){
		return false;
	}
	else{
		q = FIRST(l);
		while((NEXT(q) != FIRST(l)) && q != p){
			q = NEXT(q);
		}
		return q == p;
	}
}

void insertFirst(List *l, ElType val) {
	Address p, last;
	p = allocate(val);
	if(p != NULL){
		if(isEmpty(*l)){
			NEXT(p) = p;
		}
		else{
			last = FIRST(*l);
			while(NEXT(last) != FIRST(*l)){
				last = NEXT(last);
			}
			NEXT(p) = FIRST(*l);
			NEXT(last) = p;
		}
		FIRST(*l) = p;
	}
}

void insertLast(List *l, ElType val) {
	if(isEmpty(*l)){
		insertFirst(l, val);
	}
	else{
		Address last;
		Address p = allocate(val);
		if(p != NULL){
			last = FIRST(*l);
			while(NEXT(last) != FIRST(*l)){
				last = NEXT(last);
			}
			NEXT(last) = p;
			NEXT(p) = FIRST(*l);
		}
	}
}

void deleteFirst(List *l, ElType * val) {
	Address p, last;
	p = FIRST(*l);
	*val = INFO(p);
	if(NEXT(FIRST(*l)) == FIRST(*l)){ 
		FIRST(*l) = NULL;
	}
	else{
		last = FIRST(*l);
		while(NEXT(last) != FIRST(*l)){
			last = NEXT(last);
		}
		FIRST(*l) = NEXT(FIRST(*l));
		NEXT(last) = FIRST(*l);
	}
	free(p);
}

void deleteLast(List *l, ElType * val) {
	Address last;
	Address pLast;
	last = FIRST(*l);
	pLast = NULL;
	while(NEXT(last) != FIRST(*l)){
		pLast = last;
		last = NEXT(last);
	}
	if(pLast == NULL){
		FIRST(*l) = NULL;
	}
	else{
		NEXT(pLast) = FIRST(*l);
	}
	*val = INFO(last);
	free(last);
}

void displayList(List l) {
	if(isEmpty(l)){
		printf("[]");
	}
	else{
		Address p = l.first;
		printf("[");
		do{
			if(NEXT(p) == FIRST(l)){
				printf("%i", p->info);
			}
			else{
				printf("%i,", p->info);
			}
			p = p->next;
		} while(p != FIRST(l));
		printf("]");
	}
}
