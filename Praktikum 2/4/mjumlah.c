#include <stdio.h>
#include "liststatik.h"

int main() {
	int i;
	ListStatik arr1, arr2, res, kecil;
	readList(&arr1);
	readList(&arr2);
	int batas;
	if (listLength(arr1) > listLength(arr2)) {
		batas = listLength(arr2);
		res = arr1;
		kecil = arr2;
	}
	else {
		batas = listLength(arr1);
		res = arr2;
		kecil = arr1;
	}
	
	for (i = 0; i < batas; i++) {
		ELMT(res, listLength(res) - i - 1) += ELMT(kecil, listLength(kecil) - i - 1);
	}

	for (i = listLength(res) - 1; i > 0; i--) {
		if (ELMT(res, i) >= 10) {
			ELMT(res, i - 1) += ELMT(res, i) / 10;
			ELMT(res, i) %= 10;
		}
	}

	if (ELMT(res, 0) >= 10) {
		insertFirst(&res, ELMT(res, 0) / 10);
		ELMT(res, 1) %= 10;
	}

	printList(res);
	printf("\n");
}
