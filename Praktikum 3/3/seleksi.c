#include <stdio.h>

int main() {
	int it, cap, n, i, j, input[2], neff = 0;
	scanf("%d", &cap);
	int arr[cap];

	for (i = 0; i < cap; i++) {
		arr[i] = -999;
	}

	scanf("%d", &n);
	for (it = 0; it < n; it++) {
		scanf("%d", &input[0]);
		if (input[0] == 1) {
			scanf("%d", &input[1]);
			if (neff == 0) {
				arr[0] = input[1];
				neff++;
			}
			else {
				arr[neff] = input[1];
				neff++;
				for (j = 0; j < neff; j++) {
					if (arr[j] < input[1]) {
						arr[j] = -999;
						neff--;
					}
				}
			}
		}

		else if (input[0] == 2) {
			printf("%d\n", neff);
			printf("[");
			for (i = 0; i < neff-1; i++) {
				if (arr[i] == -999){
					continue;
				}
				else{
					printf("%d,", arr[i]);
				}
			}

			if (arr[neff-1] == -999) {
				printf("]\n");
			}

			else{
				printf("%d]\n", arr[neff-1]);
			}
		}
	}
}
