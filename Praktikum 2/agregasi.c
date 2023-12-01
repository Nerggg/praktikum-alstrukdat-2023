#include <stdio.h>
#include "liststatik.h"

int main() {
	int i, n, j, target, temp, idx = -1;
	boolean ada = true;
	float mean = 0;
	ListStatik l;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &ELMT(l, i));
		mean += ELMT(l, i);
	}
	mean /= n;
	scanf("%d", &target);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1; j++) {
			if (ELMT(l, j) > ELMT(l, j + 1)) {
				temp = ELMT(l, j);
				ELMT(l, j) = ELMT(l, j + 1);
				ELMT(l, j + 1) = temp;
			}
		}
	}
	i = 0;
	while (ada == true && i < n) {
		if (ELMT(l, i) == target) {
			idx = i;
			ada = false;
		}
		i++;
	}
	printf("[%d", ELMT(l, 0));
	for (i = 1; i < n - 1; i++) {
		printf(",%d", ELMT(l, i));
	}		
	printf(",%d]\n", ELMT(l, n - 1));
	printf("Average: %0.2f\n", mean);
	if (idx == -1) {
		printf("%d tidak ada\n", target);
	}
	else {
		printf("%d\n", idx);
	}
	if (target == ELMT(l, n - 1)) {
		printf("X maksimum\n");
	}
	if (target == ELMT(l, 0)) {
		printf("X minimum\n");
	}
	if (n % 2 == 0){
		if (target == ELMT(l, (n/2) - 1)) {
			printf("X median\n");
		}
	}
	else {
		if (target == ELMT(l, (n/2))) {
			printf("X median\n");
		}
	}
}
