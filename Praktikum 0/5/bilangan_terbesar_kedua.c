#include <stdio.h>

int main() {
	int banyak, besar1=0, besar2=1, input, temp, i = 0;
	scanf("%d", &banyak);
	while (i<banyak) {
		scanf("%d", &input);
		if (input > besar2) {
			besar2 = input;
		}
		if (besar2 > besar1) {
			temp = besar2;
			besar2 = besar1;
			besar1 = temp;
		}
		i++;
	}
	printf("%d\n", besar2);
	return 0;
}
