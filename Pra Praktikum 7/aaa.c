#include "queue.c"

int main() {
	Queue q;
	CreateQueue(&q);
	int temp;
	for (int i = 0; i < 100; i++) {
		enqueue(&q, i);
	}
//	for (int j = 0; j < 30; j++) {
//		dequeue(&q, &temp);
//	}
//	for (int i = 0; i < 30; i++) {
//		enqueue(&q, i);
//	}
	printf("head %d\n", IDX_HEAD(q));
	printf("tail %d\n", IDX_TAIL(q));
	printf("length %d\n", length(q));
	printf("full? %d\n", isFull(q));
	displayQueue(q);
}
