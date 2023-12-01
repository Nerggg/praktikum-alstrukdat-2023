#include <stdio.h>
#include "stacklinked.c"

int main() {
    Stack s;
    int temp;
    Address p;
    CreateStack(&s);
    for (int i = 1; i <= 10; i++) {
        push(&s, i);
    }
    pop(&s, &temp);
    DisplayStack(s);
}
