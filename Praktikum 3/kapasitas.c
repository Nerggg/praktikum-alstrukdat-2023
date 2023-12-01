#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "boolean.h"
#include "listdin.h"

int main(){
    ListDin l;
    int x, q, opt;
    IdxType i;

    CreateListDin(&l, 0);
    scanf("%d", &q);

    for(i=0; i<q; i++){
        scanf("%d", &opt);
        if(opt == 1){
            scanf("%d", &x);
            if(CAPACITY(l) == 0){
                CAPACITY(l) = 1;
                insertLast(&l,x);
            }
            else if (isFull(l)){
                CAPACITY(l) *= 2;
                insertLast(&l,x);
            }
            else{
                insertLast(&l,x);
            }
        }

        else if(opt == 2){
            deleteLast(&l, &x);
            if(NEFF(l) <= (CAPACITY(l)/2)){
                CAPACITY(l) = CAPACITY(l)/2;
            }
        }

        else if(opt == 3){
            printf("%d ", CAPACITY(l));
            printList(l);
            printf("\n");
        }
    }
    return 0;
}
