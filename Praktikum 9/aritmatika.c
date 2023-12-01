#include <stdio.h>
#include "list_circular.h"

int main() {
    int n, i, temp, a, b;
    List l;
    boolean bisa = true;
    CreateList(&l);
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        insertLast(&l, temp);
    }
    deleteFirst(&l, &b);
    deleteFirst(&l, &temp);
    a = temp - b;
    for (i = 3; i <= n; i++) {
        deleteFirst(&l, &temp);
        if (temp != a*(i-1)+b) {
            bisa = false;
            break;
        }
    }

    if (bisa) {
        printf("%d %d\n", a, b);
    }
    else {
        printf("0 0\n");
    }
}