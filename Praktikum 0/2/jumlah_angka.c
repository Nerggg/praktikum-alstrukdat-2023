#include <stdio.h>

int main() {
	int num, res = 0;
	scanf("%d", &num);
	while (num > 0) {
		res += num%10;
		num /= 10;
	}
	printf("%d\n", res);
	return 0;
}
