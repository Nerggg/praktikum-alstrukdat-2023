#include <stdio.h>
#include "queue.h"

int main() {
    int opt, t, temp;
    int total = 0, banyak = 0;
    Queue q;
    CreateQueue(&q);
    while (true) {
        scanf("%d", &opt);
        if (opt == 0) {
            break;
        }
        else if (opt == 2) {
            if (isEmpty(q)) {
                printf("Queue kosong\n");
            }
            else {
                dequeue(&q, &temp);
                total += temp;
                banyak++;
            }
        }
        else if (opt == 1) {
            scanf("%d", &t);
            if (isFull(q)) {
                printf("Queue penuh\n");
            }
            else {
                enqueue(&q, t);
            }
        }
    }

    printf("%d\n", banyak);
    if (banyak == 0) {
        printf("Tidak bisa dihitung\n");
    }
    else {
        float mean = (float)total/banyak;
        printf("%.2f\n", mean);
    }
}