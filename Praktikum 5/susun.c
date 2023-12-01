#include <stdio.h>
#include "charmachine.h"
#include "wordmachine.h"

int main() {
    Word arr[100];
    
    STARTWORD();
    int arrlength = 0;

    while (!EndWord) {
        arr[arrlength] = currentWord;
        arrlength++;
        ADVWORD();
    }

    int i, j;
    for (i = 1; i < arrlength; i++) {
        j = i;

        boolean lessThanPrevious, same;
        Word curr, prev;
        do {
            lessThanPrevious = false;
            same = true;

            curr = arr[j];
            prev = arr[j - 1];
            
            int k = 0;
            while ((k < curr.Length) && (k < prev.Length) && same) {
                lessThanPrevious = (curr.TabWord[k] < prev.TabWord[k]) ? true : lessThanPrevious;
                same = (curr.TabWord[k] != prev.TabWord[k]) ? false : same;
                k++;
            }

            if (!lessThanPrevious & same) {
                lessThanPrevious = (curr.Length < prev.Length) ? true : lessThanPrevious;
            }

            if (lessThanPrevious) {
                arr[j] = prev;
                arr[j - 1] = curr;
            }

            j--;
        } while ((j > 0) && lessThanPrevious);
    }

    int l;
    for (l = 0; l < i; l++) {
        int m;
        for (m = 0; m < arr[l].Length; m++) {
            printf("%c", arr[l].TabWord[m]);
        }
        printf("\n");
    }

    return 0;
}