#include <stdio.h>

int main() {
	int satu, dua, i, isatu = 0, idua = 0;
	scanf("%d", &satu);
	int tumsatu[satu];
	for (i = 0; i < satu; i++) {
		scanf("%d", &tumsatu[i]);
	}
	scanf("%d", &dua);
	int tumdua[dua];
	for (i = 0; i < dua; i++) {
		scanf("%d", &tumdua[i]);
	}

	int hasil[satu+dua];

	for (i = 0; i < satu+dua; i++) {
		if (isatu == satu) {
			hasil[i] = tumdua[idua];
			idua++;
		}

		else if (idua == dua) {
			hasil[i] = tumsatu[isatu];
			isatu++;
		}

		else {
			if (tumsatu[isatu] >= tumdua[idua]) {
				hasil[i] = tumsatu[isatu];
				isatu++;
			}
			else {
				hasil[i] = tumdua[idua];
				idua++;
			}
		}
	}

	printf("[");
	for (i = 0; i < satu+dua-1; i++) {
		printf("%d,", hasil[i]);
	}
	printf("%d]\n", hasil[satu+dua-1]);
}
