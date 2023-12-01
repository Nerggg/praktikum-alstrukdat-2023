#include <stdio.h>
#include "queue.h"

int find(int a) {
    int i, j, res1 = a, res2 = a;
    for (i = 1; i < a; i++) {
        for (j = a; j > 0; j--) {
            if (i * j == a) {
                if ((i + j) < (res1 + res2)) {
                    res1 = i;
                    res2 = j;
                }
            }
        }
    }

    if (res1 > res2) {
        return res1;
    }
    else {
        return res2;
    }
}

int step(int a) {
    int num = 0, temp = a;
    while (a > 0) {
        a = find(a);
        if (temp == a) {
            a--;
            num++;
        }
        else {
            num++;
        }
        temp = a;
    }
    return num;
}

int main() {
    Queue q;
    CreateQueue(&q);
    int n, inp, res=1, temp, ntemp;
    scanf("%d", &n);
    ntemp = n;

    if (n == 0) {
        printf("%d\n", 0);
    }

    else {
        while (n > 0) {
            scanf("%d", &inp);
            enqueue(&q, inp);
            n--;
        }
        n = ntemp;
        while (n > 0) {
            dequeue(&q, &temp);
            res*=step(temp);
            n--;
        }
        printf("%d\n", res);
    }
}