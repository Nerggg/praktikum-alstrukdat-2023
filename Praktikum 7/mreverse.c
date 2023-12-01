#include <stdio.h>
#include "queue.h"

int main() {
    Queue q;
    CreateQueue(&q);
    int a, b, inp, i;
    scanf("%d", &a);
    scanf("%d", &b);
    while (a > 0) {
        scanf("%d", &inp);
        enqueue(&q, inp);
        a--;
    }
    int temp[b];
    for (i = 0; i < b; i++) {
        temp[i] = q.buffer[i];
    }
    for (i = 0; i < b; i++) {
        q.buffer[i] = temp[b-i-1];
    }
    displayQueue(q);
}