#include <stdlib.h>
#include <stdio.h>
#include "listdin.h"

void CreateListDin(ListDin *l, int capacity){
    BUFFER(*l) = (ElType *) malloc(capacity * sizeof(ElType));
    CAPACITY(*l) = capacity;
    NEFF(*l) = 0;
}

void dealocateList(ListDin *l){
    free(BUFFER(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int listLength(ListDin l){
    return NEFF(l);
}

IdxType getFirstIdx(ListDin l){
    return IDX_MIN;
}

IdxType getLastIdx(ListDin l){
    return (IdxType) (listLength(l) - 1);
}

boolean isIdxValid(ListDin l, int i){
    return (i >= 0 && i < (IdxType) CAPACITY(l));
}
boolean isIdxEff(ListDin l, IdxType i)
{
    return (i >= 0 && i <= getLastIdx(l));
}

boolean isEmpty(ListDin l){
    return (NEFF(l) == 0);
}
boolean isFull(ListDin l){
    return (NEFF(l) == CAPACITY(l));
}

void readList(ListDin *l){
    IdxType i;
    int N;

    do {
        scanf("%d", &N);
    } while(N < 0 || N > CAPACITY(*l));

    for (i = 0; i < (IdxType) N; i++) {
        scanf("%d", &ELMT(*l, i));
    }

    NEFF(*l) = N;
}
void printList(ListDin l){
    IdxType i;

    printf("[");
    for (i = 0; i <= getLastIdx(l); i++) {
        if (i != getLastIdx(l)) {
            printf("%d,", ELMT(l, i));
        }
        else {
            printf("%d", ELMT(l, i));
        }
    }
    printf("]");
}

ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin l;
    IdxType i;

    CreateListDin(&l, listLength(l1));

    for (i = 0; i <= getLastIdx(l1); i++) {
        if (plus) {
            ELMT(l, i) = ELMT(l1, i) + ELMT(l2, i);
        }
        else {
            ELMT(l, i) = ELMT(l1, i) - ELMT(l2, i);
        }
    }

    NEFF(l) = listLength(l1);

    return l;
}

boolean isListEqual(ListDin l1, ListDin l2){
    IdxType i;
    boolean hasil;

    hasil = true;

    if (listLength(l1) != listLength(l2)) {
        hasil = false;
    }
    else {
        i = 0;
        while (i <= getLastIdx(l1) && hasil) {
            if (ELMT(l1, i) != ELMT(l2, i)) {
                hasil = false;
            }
            i++;
        }
    }

    return hasil;
}

IdxType indexOf(ListDin l, ElType val){
    IdxType i, index;

    index = IDX_UNDEF;
    i = 0;

    while (i <= getLastIdx(l) && index == IDX_UNDEF) {
        if (ELMT(l, i) == val) {
            index = i;
        }
        i++;
    }

    return index;
}

void extremeValues(ListDin l, ElType *max, ElType *min){
    IdxType i;

    *max = ELMT(l, 0);
    *min = ELMT(l, 0);

    for (i = 1; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) > *max) {
            *max = ELMT(l, i);
        }
        if (ELMT(l, i) < *min) {
            *min = ELMT(l, i);
        }
    }
}

void copyList(ListDin lIn, ListDin *lOut){
    IdxType i;

    CreateListDin(lOut, CAPACITY(lIn));

    NEFF(*lOut) = listLength(lIn);

    for (i = 0; i <= getLastIdx(lIn); i++) {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
}
ElType sumList(ListDin l){
    ElType hasil;
    IdxType i;

    hasil = 0;

    for (i = 0; i <= getLastIdx(l); i++) {
        hasil += ELMT(l, i);
    }

    return hasil;
}
int countVal(ListDin l, ElType val){
    int hasil;
    IdxType i;

    hasil = 0;

    for (i = 0; i <= getLastIdx(l); i++) {
        if (ELMT(l, i) == val) {
            hasil++;
        }
    }

    return hasil;
}

void sort(ListDin *l, boolean asc){
    IdxType i, pos;
    ElType temp;

    for (i = 1; i <= getLastIdx(*l); i++) {
        pos = i;
        if (asc) {
            while ((pos > 0) && (ELMT(*l, pos) < ELMT(*l, pos - 1))) {
                temp = ELMT(*l, pos);
                ELMT(*l, pos) = ELMT(*l, pos - 1);
                ELMT(*l, pos - 1) = temp;

                pos--;
            }
        } else {
            while ((pos > 0) && (ELMT(*l, pos) > ELMT(*l, pos - 1))) {
                temp = ELMT(*l, pos);
                ELMT(*l, pos) = ELMT(*l, pos - 1);
                ELMT(*l, pos - 1) = temp;

                pos--;
            }
        }
    }
}

void insertLast(ListDin *l, ElType val){
    ELMT(*l, getLastIdx(*l) + 1) = val;
    NEFF(*l)++;
}

void deleteLast(ListDin *l, ElType *val){
    *val = ELMT(*l, getLastIdx(*l));
    NEFF(*l)--;
}

void expandList(ListDin *l, int num){
    int prevCapacity, prevNeff;
    IdxType i;
    ListDin temp;

    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);
    prevNeff = NEFF(*l);

    dealocateList(l);

    CreateListDin(l, prevCapacity + num);
    NEFF(*l) = prevNeff;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void shrinkList(ListDin *l, int num){
    int prevCapacity, prevNeff;
    IdxType i;
    ListDin temp;

    copyList(*l, &temp);
    prevCapacity = CAPACITY(*l);
    prevNeff = NEFF(*l);

    dealocateList(l);

    CreateListDin(l, prevCapacity - num);
    NEFF(*l) = prevNeff;

    for (i = 0; i <= getLastIdx(*l); i++) {
        ELMT(*l, i) = ELMT(temp, i);
    }
}

void compressList(ListDin *l){
    ListDin temp;
    CreateListDin(&temp, listLength(*l));
    NEFF(temp) = NEFF(*l);

    int i;
    for(i = 0; i < listLength(*l); i++){
        ELMT(temp, i) = ELMT(*l, i);
    }
    dealocateList(l);
    BUFFER(*l) = BUFFER(temp);
    CAPACITY(*l) = CAPACITY(temp);
    NEFF(*l) = NEFF(temp);
}