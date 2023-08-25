#include <stdio.h>

int main() {
	int i = 1, domba, sayang;
	scanf("%d", &domba);
	scanf("%d", &sayang);
	while (i<=domba) {
		if (i % sayang == 0) {
			printf("happy\n");
		}
		else {
			printf("%d\n", i);
		}
		i++;
	}
	return 0;
}
