#include <stdio.h>
#include "listdin.h"

int main() {
	ListDin arr, temp;
	int n, i, iterate, hapus;
	int input[2];
	int kosong = 1;
	scanf("%d", &n);
	for (iterate = 0; iterate < n; iterate++) {
		scanf("%d", &input[0]);
//		printf("input 0 adalah %d\n", input[0]);
//		printf("nilai i adalah %d\n", iterate);
		if (input[0] == 1) {
			scanf("%d", &input[1]);
//			printf("input 1 adalah %d\n", input[1]);
			if (kosong == 1) {
				CreateListDin(&arr, 1);
				insertLast(&arr, input[1]);
				kosong = 0;
			}
			else {
				copyList(arr, &temp);
				dealocateList(&arr);
				CreateListDin(&arr, CAPACITY(temp)*2);
				for (i = 0; i < NEFF(temp); i++) {
					ELMT(arr, i) = ELMT(temp, i);
					NEFF(arr)++;
				}
				insertLast(&arr, input[1]);
			}
		}

		else if (input[0] == 2) {
			deleteLast(&arr, &hapus);
			if (NEFF(arr) <= CAPACITY(arr)/2) {
				copyList(arr, &temp);
				dealocateList(&arr);
				CreateListDin(&arr, CAPACITY(temp)/2);
				for (i = 0; i < NEFF(temp); i++) {
					ELMT(arr, i) = ELMT(temp, i);
					NEFF(arr)++;
				}
			}
		}

		else if (input[0] == 3) {
			printf("%d ", CAPACITY(arr));
			printList(arr);
			printf("\n");
		}
	}
}
