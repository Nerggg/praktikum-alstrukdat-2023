#include <stdio.h>
#include "list_circular.c"

int main() {
	List l;
	Address p;
	CreateList(&l);
	insertFirst(&l, 10);
	insertFirst(&l, 20);
	p = search(l, 10);
	displayList(l);
	printf("\n");
	printf("%d\n", p->info);
	p = p->next;
	printf("%d\n", p->info);
	if (addrSearch(l, p)) {
		printf("ada\n");
	}
	else {
		printf("gadak\n");
	}
}
