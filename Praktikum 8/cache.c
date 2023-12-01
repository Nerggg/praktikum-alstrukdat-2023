#include <stdio.h>
#include "boolean.h"
#include "listlinier.h"

int main(){
    List cache;
    int size, n, num, miss, hit, i;
    ElType val;
    float ratio;
    ratio = 0;
    hit = 0;
    miss = 0;
    CreateList(&cache);
    
    scanf("%d", &size);
    scanf("%d", &n);

    for (i = 0; i < n; i++){
        scanf("%d", &num);
        if (isEmpty(cache)){
            if (size > 0){
                insertFirst(&cache, num);
            }
            miss += 1;
            printf("miss ");
            displayList(cache);
            printf("\n");
        } else if (indexOf(cache, num) != IDX_UNDEF){
            deleteAt(&cache, indexOf(cache, num), &val);
            insertFirst(&cache, num);
            hit += 1;
            printf("hit ");
            displayList(cache);
            printf("\n");
        } else if ((indexOf(cache, num) == IDX_UNDEF) && (length(cache) < size)){
            insertFirst(&cache, num);
            miss += 1;
            printf("miss ");
            displayList(cache);
            printf("\n");
        } else if ((indexOf(cache, num) == IDX_UNDEF) && (length(cache) == size)){
            deleteLast(&cache, &val);
            insertFirst(&cache, num);
            miss += 1;
            printf("miss ");
            displayList(cache);
            printf("\n");
        }
    }

    if ((size != 0) && (n != 0)){
        ratio = hit / (float) (hit + miss);
    }

    printf("hit ratio: %.2f\n", ratio);

    return 0;
}
