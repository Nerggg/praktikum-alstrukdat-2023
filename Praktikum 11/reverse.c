#include "listrec.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    List l1=NULL, l2=NULL, hasil=NULL;
    int n, i, temp, q, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &temp);
        hasil = konsb(hasil, temp);
    }
    int length = n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &q);
        for (j = 0; j < q; j++) {
            l1 = konso(l1, head(hasil));
            hasil = tail(hasil);
        }
        // printf("headnya %d\n", head(hasil));
        for (j = 0; j < length-q; j++) {
            // printf("headnya %d\n", head(hasil));
            l2 = konso(l2, head(hasil));
            hasil = tail(hasil);
        }
        // printf("l1\n");
        // displayList(l1);
        // printf("l2\n");
        // displayList(l2);
        hasil = NULL;        
        for (k = 0; k < length; k++) {
            if (!isEmpty(l1)) {
                hasil = konsb(hasil, head(l1));
                l1 = tail(l1);
            }
            else if (!isEmpty(l2)) {
                hasil = konsb(hasil, head(l2));
                l2 = tail(l2);
            }
        }
        l1 = NULL;
        l2 = NULL;
    }

    displayList(hasil);
}