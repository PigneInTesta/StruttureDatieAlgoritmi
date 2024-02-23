#include "no_dups.h"

int main(void) {

	Item* list_A = NULL;
	Item* list_B = NULL;

	ElemType a[] = { 1, 2, 3, 4, 5, 6, 7 };
	size_t dim_A = sizeof(a) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, a + i);
	}

	Item* res = RemoveDuplicates(list_A);
	ListDelete(res);

	res = RemoveDuplicates(list_B);
	ListDelete(res);

	ListDelete(list_A);
	ListDelete(list_B);

	return 0;
}