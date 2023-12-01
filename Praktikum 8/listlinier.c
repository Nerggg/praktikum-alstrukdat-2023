#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

Address newNode(ElType val) {
    Address p = (Address) malloc(sizeof(Node));

    if (p != NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }

    return p;
}

void CreateList(List *l) {
    *l = NULL;
}

boolean isEmpty(List l) {
    return (l == NULL);
}

ElType getElmt(List l, int idx) {
    int i = 0;
    Address p = l;

    while (i < idx) {
        p = NEXT(p);
        i += 1;
    }

    return INFO(p);
}

void setElmt(List *l, int idx, ElType val) {
    int i = 0;
    Address p = *l;

    while (i < idx) {
        p = NEXT(p);
        i += 1;
    }

    INFO(p) = val;
}

int indexOf(List l, ElType val) {
    int i = 0;
    Address p = l;

    while (p != NULL && INFO(p) != val) {
        p = NEXT(p);
        i += 1;
    }

    int ret = (p == NULL) ? IDX_UNDEF : i;
    return ret;
}

void insertFirst(List *l, ElType val) {
    Address p = newNode(val);
    if (p != NULL) {
        NEXT(p) = *l;
        *l = p;
    }
}

void insertLast(List *l, ElType val) {
    if (isEmpty(*l)) {
        insertFirst(l, val);
    } else {
        Address p = newNode(val);
        if (p != NULL) {
            Address prevNode = *l;
            while (NEXT(prevNode) != NULL) {
                prevNode = NEXT(prevNode);
            }
            NEXT(prevNode) = p;
        }
    }

}

void insertAt(List *l, ElType val, int idx) {
    Address p, loc;
    int ctr;
    if (idx == 0) {
        insertFirst(l, val);
    } else {
        p = newNode(val);
        if (p != NULL) {
            ctr = 0;
            loc = FIRST(*l);
            while (ctr < idx - 1) {
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}

void deleteFirst(List *l, ElType *val) {
    *val = INFO(*l);
    Address temp = *l;
    *l = NEXT(*l);
    free(temp);
}

void deleteLast(List *l, ElType *val) {
    Address p, loc;
    p = FIRST(*l);
    loc = NULL;

    while (NEXT(p) != NULL) {
        loc = p;
        p = NEXT(p);
    }

    if (loc == NULL) {
        FIRST(*l) = NULL;
    } else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);
}

void deleteAt(List *l, int idx, ElType *val) {
    Address p, loc;
    int ctr;
    if (idx == 0) {
        deleteFirst(l, val);
     } else {
        ctr = 0;
        loc = FIRST(*l);

        while (ctr < idx - 1) {
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }
}

void displayList(List l) {
    Address p;

    printf("[");
    p = FIRST(l);
    while (p != NULL) {
        if (NEXT(p) == NULL) {
            printf("%d", INFO(p));
        } else {
            printf("%d,", INFO(p));
        }
        p = NEXT(p);
    }
    printf("]");
}

int length(List l) {
    Address p = l;
    
    int count = 0;
    while (p != NULL) {
        p = NEXT(p);
        count += 1;
    }
    return count;
}

List concat(List l1, List l2) {
    Address p;
    List l3;

    CreateList(&l3);

    p = FIRST(l1);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    p = FIRST(l2);
    while (p != NULL) {
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }

    return l3;
}

boolean fSearch(List L, Address P) {
    Address p = L;

    boolean found = false;
    while (!found && p != NULL) {
        if (p == P) {
            found = true;
        } else {
            p = NEXT(p);
        }
    }

    return found;
}

Address searchPrec(List L, ElType X) {
    List p = L;
    if (INFO(p) == X) {
        return NULL;
    } else {
        while (NEXT(p) != NULL) {
            if (INFO(NEXT(p)) == X) {
                return p;
            } else {
                p = NEXT(p);
            }
        }
        return NULL;
    }
}

ElType maxValue(List l) {
    List p = l;
    
    int max = INFO(p);
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
        }
        p = NEXT(p);
    }
    
    return max;
}

Address adrMax(List l) {
    List p = l;
    
    int max = INFO(p);
    Address addMax = p;
    while (p != NULL) {
        if (INFO(p) > max) {
            max = INFO(p);
            addMax = p;
        }
        p = NEXT(p);
    }
    
    return addMax;
}

ElType minValue(List l) {
    List p = l;
    
    int min = INFO(p);
    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
        }
        p = NEXT(p);
    }
    
    return min;
}

Address adrMin(List l) {
    List p = l;
    
    int min = INFO(p);
    Address addMin = p;

    while (p != NULL) {
        if (INFO(p) < min) {
            min = INFO(p);
            addMin = p;
        }
        p = NEXT(p);
    }
    
    return addMin;
}

float average(List L) {
    List p = L;

    int sum = 0;
    int count = 0;
    while (p != NULL) {
        sum += INFO(p);
        count += 1;

        p = NEXT(p);
    }
    if (!count) return 0;
    else return sum / (float) count; 
}

void deleteAll(List *l) {
    int val;

    while(!isEmpty(*l)) {
        deleteFirst(l, &val);
    }
}

void copyList(List *l1, List *l2) {
    *l2 = *l1;
}

void inverseList(List *l) {
    List p = *l;
    Address prev = NULL;
    Address nxt = NULL;
    if (length(*l) > 1) {
        while (p != NULL) {
            nxt = NEXT(p);
            NEXT(p) = prev;

            prev = p;
            p = nxt;
        }
        *l = prev;
    }
}