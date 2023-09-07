#include <stdio.h>
#include "liststatik.h"

void CreateListStatik(ListStatik *l) {
	ListStatik temp;
	int i;
	for (i = 0; i < CAPACITY; i++){
		ELMT(temp, i) = MARK;
	}
	*l = temp;
}

int listLength(ListStatik l) {
	int i;
	for (i = getFirstIdx(l); i < CAPACITY; i++) {
		if (ELMT(l, i) == MARK) {
			return i - getFirstIdx(l);
		}
	}
	return CAPACITY;
}

IdxType getFirstIdx(ListStatik l) {
	int i;
	for (i = 0; i < CAPACITY; i++) {
		if (ELMT(l, i) != MARK) {
			return i;
		}
	}
	return 0;
}

IdxType getLastIdx(ListStatik l) {
	int i;
	for (i = getFirstIdx(l); i < CAPACITY - 1; i++) {
		if (ELMT(l, i + 1) == MARK) {
			return i;
		}
	}
	return CAPACITY-1;
}

boolean isIdxValid(ListStatik l, IdxType i) {
	if (i >= 0 && i < CAPACITY) {
		return true;
	}
	else {
		return false;
	}
}

boolean isIdxEff(ListStatik l, IdxType i) {
	if (i >= getFirstIdx(l) && i <= getLastIdx(l)) {
		return true;
	}
	else {
		return false;
	}
}

boolean isEmpty(ListStatik l) {
	if (listLength(l) == 0) {
		return true;
	}
	else {
		return false;
	}
}

boolean isFull(ListStatik l) {
	if (listLength(l) == CAPACITY) {
		return true;
	}
	else {
		return false;
	}
}

void readList(ListStatik *l) {
	int n, i;
	ListStatik temp;
	CreateListStatik(&temp);
	scanf("%d", &n);
	while (n < 0 || n > CAPACITY) {
		scanf("%d", &n);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &ELMT(temp, i));
	}
	*l = temp;
}

void printList(ListStatik l) {
	if (isEmpty(l) == true) {
		printf("[]");
	}
	else {
		int idx = getFirstIdx(l);
		printf("[%d", ELMT(l, idx));
		idx++; 
		while (idx <= getLastIdx(l)) {
			printf(",%d", ELMT(l, idx));
			idx++;
		}
		printf("]");
	}
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus) {
	ListStatik res;
	CreateListStatik(&res);
	int i = getFirstIdx(l1);
	if (plus == true) {
		while (i <= getLastIdx(l1)) {
			ELMT(res, i) = ELMT(l1, i) + ELMT(l2, i);
			i++;
		}
	}
	else {
		while (i <= getLastIdx(l1)) {
			ELMT(res, i) = ELMT(l1, i) - ELMT(l2, i);
			i++;
		}
	}
	return res;
}

boolean isListEqual(ListStatik l1, ListStatik l2) {
	if (listLength(l1) == listLength(l2)) {
		int i;
		for (i = getFirstIdx(l1); i <= getLastIdx(l1); i++) {
			if (ELMT(l1, i) != ELMT(l2, i)) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}

int indexOf(ListStatik l, ElType val) {
	int i = getFirstIdx(l);
	while(i <= getLastIdx(l)) {
		if (ELMT(l, i) == val) {
			return i;
		}
		i++;
	}
	return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min) {
	*max = ELMT(l, 0);
	*min = ELMT(l, 0);
	int i = getFirstIdx(l);
	while(i <= getLastIdx(l)) {
		if (ELMT(l, i) > *max) {
			*max = ELMT(l, i);
		}
		if (ELMT(l, i) < *min) {
			*min = ELMT(l, i);
		}
		i++;
	}

}

void insertFirst(ListStatik *l, ElType val) {
	ListStatik temp = *l;
	int i;
	ELMT(*l, getFirstIdx(*l)) = val;
	for (i = getFirstIdx(temp) + 1; i <= getLastIdx(temp) + 1; i++) {
		ELMT(*l, i) = ELMT(temp, i - 1);
	}
}

void insertAt(ListStatik *l, ElType val, IdxType idx) {
	ListStatik temp = *l;
	int i, minus = 0;
	for (i = getFirstIdx(temp); i <= getLastIdx(temp) + 1; i++) {
		if (i == idx) {
			ELMT(*l, i) = val;
			minus = 1;
		}
		else {
			ELMT(*l, i) = ELMT(temp, i - minus);
		}
	}
}

void insertLast(ListStatik *l, ElType val) {
//	ListStatik temp = *l;
//	int i;
//	for (i = getFirstIdx(temp); i <= getLastIdx(temp); i++) {
//		ELMT(*l, i) = ELMT(temp, i);
//	}
	ELMT(*l, getLastIdx(*l) + 1) = val;
}

void deleteFirst(ListStatik *l, ElType *val) {
	int i;
	*val = ELMT(*l, getFirstIdx(*l));
	for (i = getFirstIdx(*l); i <= getLastIdx(*l) - 1; i++) {
		ELMT(*l, i) = ELMT(*l, i + 1);
	}
	ELMT(*l, getLastIdx(*l)) = MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx) {
	ListStatik temp = *l;
	int i;
	*val = ELMT(*l, idx);
	for (i = idx; i <= getLastIdx(*l) - 1; i++) {
		ELMT(*l, i) = ELMT(temp, i + 1);
	}
	ELMT(*l, getLastIdx(*l)) = MARK;
}

void deleteLast(ListStatik *l, ElType *val) {
	*val = ELMT(*l, getLastIdx(*l));
	ELMT(*l, getLastIdx(*l)) = MARK;
}

void sortList(ListStatik *l, boolean asc) {
	int i, j, temp;
	if (asc == true) {
		for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++){
			for (j = getFirstIdx(*l); j <= getLastIdx(*l) - 1; j++){
				if (ELMT(*l, j) > ELMT(*l, j + 1)){
					temp = ELMT(*l, j);
					ELMT(*l, j) = ELMT(*l, j + 1);
					ELMT(*l, j + 1) = temp;
				}
			}			
		}
	}
	else if (asc == false) {
		for (i = getFirstIdx(*l); i <= getLastIdx(*l); i++){
			for (j = getFirstIdx(*l); j <= getLastIdx(*l) - 1; j++){
				if (ELMT(*l, j) < ELMT(*l, j + 1)){
					temp = ELMT(*l, j);
					ELMT(*l, j) = ELMT(*l, j + 1);
					ELMT(*l, j + 1) = temp;
				}
			}			
		}
	}
}
