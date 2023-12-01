#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    ListDin l;
    IdxType i, j;
    int c, q, opt, x;
    boolean found;

    CreateListDin(&l, 0);

    scanf("%d", &c);
    scanf("%d", &q);

    for(i=0; i<q; i++){
        scanf("%d", &opt);
        if(opt == 1){
            scanf("%d", &x);
            for(j=getLastIdx(l); j>=0; j--){
                if (!(ELMT(l, j) >= x)){
                    deleteLast(&l, &ELMT(l,getLastIdx(l)));
                }
            }
            insertLast(&l, x);
        }

        if(opt == 2){
            printf("%d\n", NEFF(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}
