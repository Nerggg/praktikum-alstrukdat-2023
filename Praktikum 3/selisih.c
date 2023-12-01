#include <stdio.h>

int main() {
	int i, j, n, max, temp, min, first = 1;;
	scanf("%d", &n);
	int arr[n];

	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n-1; j++) {
			if (arr[j] > arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	
	arr[n-1]++;

//	for (i = 0; i < n; i++) {
//		printf("%d\n", arr[i]);
//	}

	printf("%d\n", arr[n-1]-arr[0]);
}
