#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = malloc(3 * sizeof(int));

	for (int i = 0; i < 3; i++) {
		arr[i] = i;
	}
	free(arr);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", arr[i]);
	}
}
