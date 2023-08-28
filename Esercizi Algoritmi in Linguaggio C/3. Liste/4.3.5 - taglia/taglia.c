#include "list.h"
#include <stdlib.h>

Item* Taglia(Item* i, int n) {
	if (n == 0) {
		ListDelete(i);
		return ListCreateEmpty();
	} else if (n < 0 || ListIsEmpty(i)) {
		return i;
	}

	Item fake_head = { .next = i };

	for (int j = 0; !ListIsEmpty(i); j++) {
		Item* tmp = i;
		i = i->next;
		if (j + 1 == n) {	
			ListDelete(ListGetTail(tmp));
			tmp->next = NULL;
			break;
		}
	}

	return fake_head.next;
}

int main(void) {

	Item* list_A = NULL;
	Item* list_B = NULL;

	const ElemType ese_A[] = { 0, 1, 2, 3 };
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	//Item* res = Taglia(list_A, -1);
	//Item* res = Taglia(list_A, 0);
	//Item* res = Taglia(list_A, 1);
	//Item* res = Taglia(list_A, 2);
	Item* res = Taglia(list_A, 3);
	//Item* res = Taglia(list_A, 4);
	//Item* res = Taglia(list_B, 2);

	ListDelete(list_A);

	return 0;
}