#include "list.h"
#include <stdlib.h>

Item* Filter(Item* i, ElemType e) {
	Item* prev = ListCreateEmpty();
	Item* tmp = i;
	Item* filtered = ListCreateEmpty();

	for (; !ListIsEmpty(tmp); ) {
		if (ElemCompare(ListGetHeadValue(tmp), &e) >= 0) {
			if (ListIsEmpty(prev)) {
				i = ListGetTail(tmp);
				free(tmp);
				tmp = i;
			} else {
				filtered = tmp;
				tmp = ListGetTail(tmp);
				prev->next = tmp;
				free(filtered);
			}
		} else {
			prev = tmp;
			tmp = ListGetTail(tmp);
		}
	}

	return i;
}

int main(void) {

	Item* list_A = ListCreateEmpty();
	Item* list_B = ListCreateEmpty();

	const ElemType ese_A[] = { 1, 5, 2, 17, 3, 26 };
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	Item* res = Filter(list_A, 5);

	ListDelete(list_A);
	ListDelete(list_B);

	return 0;
}