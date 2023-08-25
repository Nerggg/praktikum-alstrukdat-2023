#define boolean unsigned char
#define true 1
#define false 0

#include <stdio.h>

boolean cek (int num) {
	int a;
	while (num/10 > 0) {
		a = num%10;
		num /= 10;
		if (a != num%10) {
			return false;
		}
	}
	return true;
}

int main() {
	int first, last, res;
	scanf("%d", &first);
	scanf("%d", &last);
	for (int i = first+1; i<last; i++) {
		if (cek(i) == true) {
			res++;
		}
	}
	printf("%d\n", res);
	return 0;
}
