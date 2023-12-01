#include <stdio.h>
#include "matrix.h"

int main() {
	Matrix papan;
	createMatrix(8, 8, &papan);
	int white = 0, black = 0, i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			scanf("%d", &ELMT(papan, i, j));
		}
	}	
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
				if (ELMT(papan, i, j) == 1) {
					if ((i + j) % 2 != 0) {
						white++;
					}
					else {
						black++;
					}
				}
		}
	}
	printf("%d %d\n", black, white);
}