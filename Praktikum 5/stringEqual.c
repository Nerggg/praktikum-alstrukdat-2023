#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

// Prints word from Mesin Kata
int printWord(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
      printf("%c", word.TabWord[i]);
   }
}

int main() {
	Word angka;
    STARTWORD();
	
	if (currentChar == BLANK) {
		angka = currentWord;
	}

	angka.TabWord[angka.Length] = '\0';

	ADVWORD();

	if (currentWord.TabWord[4] == 'U') {
		printf("Moving %s square upwards\n", angka.TabWord);
	}
	else if (currentWord.TabWord[4] == 'D') {
		printf("Moving %s square downwards\n", angka.TabWord);
	}
	else if (currentWord.TabWord[4] == 'L') {
		printf("Moving %s square leftwards\n", angka.TabWord);
	}
	else if (currentWord.TabWord[4] == 'R') {
		printf("Moving %s square rightwards\n", angka.TabWord);
	}			

}
