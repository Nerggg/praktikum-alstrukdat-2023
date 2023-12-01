#include "stack.h"
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"
#include<stdio.h>

void displayWord(Word s){
    int i;

    for (i = 0; i < s.Length; i++){
        printf("%c", s.TabWord[i]);
    }

    printf("\n");
}

int main(){
    Word listWords[100];
    int countWord = 0;

    START();
    while(currentChar != MARK){
        ADVWORD();
        
        listWords[countWord] = currentWord;
        countWord++;
    }

    Stack num1, num2;
    CreateEmpty(&num1);
    CreateEmpty(&num2);

    int i;
    for (i = 0; i < listWords[0].Length; i++){
        Push(&num1, listWords[0].TabWord[i] - '0');
    }

    for (i = 0; i < listWords[1].Length; i++){
        Push(&num2, listWords[1].TabWord[i] - '0');
    }

    Stack selisih;
    CreateEmpty(&selisih);

    boolean carry = false;
    int zeroFlag = true;

    while (!IsEmpty(num2)){
        int val1, val2;
        Pop(&num1, &val1);
        Pop(&num2, &val2);

        if (carry) {
            val1 -= 1;
            carry = false;
        }

        if (val1 < val2){
            carry = true;
            val1 += 10;
        }

        int temp = val1 - val2;

        if (temp != 0){
            zeroFlag = false;
        }

        Push(&selisih, temp);
    }

    // printf("%d", zeroFlag);

    while (!IsEmpty(num1))
    {
        zeroFlag = false;

        int val;
        Pop(&num1, &val);

        if (carry) {
            val -= 1;
            carry = false;
        }

        Push(&selisih, val);
    }

    if (zeroFlag){
        printf("0\n");
    } else {
        
        while (InfoTop(selisih) == 0)
        {
            int temp;
            Pop(&selisih, &temp);
        }
        

        while (!IsEmpty(selisih))
        {
            int val;
            Pop(&selisih, &val);
            printf("%d", val);
        }

        printf("\n");
    
    }
}

