#include <stdio.h>
#include "liststatik.h"

int main() {
	int n1, n2, i, j, temp;
	ListStatik l1, l2, res;
	scanf("%d", &n1);
	for (i = 0; i < n1; i++) {
		scanf("%d", &ELMT(l1, i));
	}
	scanf("%d", &n2);
	for (i = 0; i < n2; i++) {
		scanf("%d", &ELMT(l2, i));
	}
	for (i = 0; i < n1; i++) {
		ELMT(res, i) = ELMT(l1, i);
	}
	for (i = n1; i < n1 + n2; i++) {
		ELMT(res, i) = ELMT(l2, i - n1);
	}
	for (i = 0; i < n1 + n2; i++) {
		for (j = 0; j < n1 + n2 - 1; j++) {
			if (ELMT(res, j) > ELMT(res, j + 1)) {
				temp = ELMT(res, j);
				ELMT(res, j) = ELMT(res, j + 1);
				ELMT(res, j + 1) = temp;
			}
		}
	}
	printf("[%d", ELMT(res, 0));
	for (i = 1; i < n1 + n2 - 1; i++) {
		printf(",%d", ELMT(res, i));
	}		
	printf(",%d]\n", ELMT(res, n1 + n2 - 1));
}
