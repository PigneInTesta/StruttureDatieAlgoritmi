#include "list.h"
#include <math.h>
#include <stdlib.h>

int ListLength(Item* i) {
	Item* tmp = i;
	int cnt = 0;
	for (; !ListIsEmpty(tmp); cnt++) {
		tmp = ListGetTail(tmp);
	}

	if (cnt % 2 == 0) {
		return cnt;
	} else {
		return cnt + 1;
	}
}

Item* Split(Item* i) {
	if (ListIsEmpty(i)) {
		return NULL;
	}

	Item* res = NULL;
	Item fake_head = { .next = i };

	for (int j = 1; !ListIsEmpty(i); j++) {
		if (j == ListLength(fake_head.next)/2) {
			res = i->next;
			/*ElemDelete(&i->next->value);
			free(&i->next->value);*/
			i->next = NULL;
		}
		i = ListGetTail(i);
	}

	return res;
}

int main(void) {

	Item* list_A = NULL;
	
	const ElemType ese_A[] = { 5, 1, 7, 3 };
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	Item* list_B = NULL;

	const ElemType ese_B[] = { 5, 1, 7, 3, 8};
	size_t dim_B = sizeof(ese_B) / sizeof(ElemType);
	for (size_t i = 0; i < dim_B; i++) {
		list_B = ListInsertBack(list_B, ese_B + i);
	}

	Item* res_A = Split(list_A);
	Item* res_B = Split(list_B);

	ListDelete(res_A);
	ListDelete(res_B);

	return 0;
}