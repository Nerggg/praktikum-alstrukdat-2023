#include "boolean.h"
#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>

boolean IsEmpty (PrioQueueChar Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q){
    int idxFull = Head(Q) - 1;

    if (idxFull <= 0){
        idxFull = Q.MaxEl - 1;
    }

    return idxFull == Tail(Q);
    
}

int NBElmt (PrioQueueChar Q){
    if (Head(Q) == Nil){
        return 0;
    }

    int length = Tail(Q) - Head(Q) + 1;

    if (length < 0){
        length += Q.MaxEl;
    }        

    return length;
}

void MakeEmpty (PrioQueueChar * Q, int Max){
   
    (*Q).T = (infotype *) malloc((Max) * sizeof(infotype));

    if ((*Q).T == NULL){
        MaxEl(*Q) = 0;
    } else {
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
        MaxEl(*Q) = Max;

    }

}

void DeAlokasi(PrioQueueChar * Q){
    free((*Q).T);
    MaxEl(*Q) = 0;
}

void Enqueue (PrioQueueChar * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        (*Q).T[0] = X;
        return;
    }

    int idx = Head(*Q);

    while(Prio(X) >= Prio((*Q).T[idx])){
        idx++;

        if (idx >= MaxEl(*Q)){
            idx = 0;
        }

        if (idx > Tail(*Q)){
            break;
        }

        if (Prio(X) < Prio((*Q).T[idx])){
            break;
        }
    }

    if (idx > Tail(*Q)){
        Tail(*Q) += 1;

        if (Tail(*Q) >= MaxEl(*Q)){
            Tail(*Q) = 0;
        }

        (*Q).T[Tail(*Q)] = X;
    } else {
        int idxTemp = Tail(*Q) + 1;

        while (idxTemp != idx){
            int idxPrev = idxTemp - 1;

            if (idxPrev < 0){
                idxPrev = MaxEl(*Q) - 1;
            }

            (*Q).T[idxTemp] = (*Q).T[idxPrev];
            idxTemp = idxPrev;
        }

        Tail(*Q) += 1;

        if (Tail(*Q) >= MaxEl(*Q)){
            Tail(*Q) = 0;
        }

        (*Q).T[idx] = X;
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X){
    if (NBElmt(*Q) == 1){
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else {
        *X = InfoHead(*Q);
        Head(*Q) += 1;
        
        if(Head(*Q) >= MaxEl(*Q)){
            Head(*Q) = 0;
        }
    }
}

void PrintPrioQueueChar (PrioQueueChar Q){
    while (!IsEmpty(Q))
    {
        infotype val;
        Dequeue(&Q, &val);

        printf("%d %c", Prio(val),Info(val));

        printf("\n");
    }

    printf("#\n");
}
