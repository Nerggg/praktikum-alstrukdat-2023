#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"
#include "boolean.h"

Word bsort(Word word) {
   int i, j;
   for (i = 0; i < word.Length; i++) {
	for (j = 0; j < word.Length-1; j++) {
			if (word.TabWord[j] > word.TabWord[j+1]) {
				char temp = word.TabWord[j];
				word.TabWord[j] = word.TabWord[j+1];
				word.TabWord[j+1] = temp;
			}
		}
   }

	// printf("ini kata yg udah di sort\n");

	// for (int i = 0; i < word.Length; i++) {
	// 	printf("%c", word.TabWord[i]);
	// }
	// printf("\n");

   return word;
}

boolean equalWord(Word kata1, Word kata2) {
	if (kata1.Length != kata2.Length) {
		return false;
	}
	else {
		boolean flag = true;
		for (int i = 0; i < kata1.Length; i++) {
			if (kata1.TabWord[i] != kata2.TabWord[i]) {
				flag = false;
				break;
			}
		}
		return flag;
	}
}

int main() {
	Word semua[100];
	int neff = 0;
	int hasil = 0;
	int k;

    STARTWORD();

	int i = 0;
	while (currentChar != MARK) {
		if (currentChar == BLANK) {
			// printf("currentwordnya %s\n", currentWord.TabWord);
			semua[i] = bsort(currentWord);
			neff++;
			i++;
			STARTWORD();
		}
	}

	// semua[i] = bsort(currentWord);
	// neff++;
	// i++;

	int j;
	for (i = 0; i < neff-1; i++) {
		for (j = i + 1; j < neff; j++) {
				if (equalWord(semua[i], semua[j])) {
					hasil++;
				}
			}
		}
	printf("%d\n", hasil);
}
