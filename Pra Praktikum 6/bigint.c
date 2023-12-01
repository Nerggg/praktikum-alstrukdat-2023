#include "stack.c"
#include "boolean.h"
#include <stdio.h>

int convert(char in[]) {
	int i, hasil = 0;
	for (i = 0; in[i] != '\0'; i++) {
		hasil = hasil * 10 + (in[i] - '0');
	}
	return hasil;
}

boolean check(char a) {
	char arr[10] = {'0','1','2','3','4','5','6','7','8','9'};
	for (int i = 0; i < 10; i++) {
		if (a == arr[i]) {
			return true;
		}
	}
	return false;
}


int main() {
	Stack bil1, bil2, hasil;
	CreateEmpty(&bil1);
	CreateEmpty(&bil2);
	CreateEmpty(&hasil);
	char inp[1];
	int out;

	scanf("%c", &inp[0]);
	while (check(inp[0])) {
		printf("masuk\n");
		Push(&bil1, convert(inp));
		scanf("%c", &inp[0]);
	}

	scanf("%c", &inp[0]);
	while (check(inp[0])) {
		printf("masuk\n");
		Push(&bil2, convert(inp));
		scanf("%c", &inp[0]);
	}

	while(!IsEmpty(bil1)) {
		Pop(&bil1, &out);
		printf("%d\n", out);
	}

	while(!IsEmpty(bil2)) {
		Pop(&bil2, &out);
		printf("%d\n", out);
	}
}
