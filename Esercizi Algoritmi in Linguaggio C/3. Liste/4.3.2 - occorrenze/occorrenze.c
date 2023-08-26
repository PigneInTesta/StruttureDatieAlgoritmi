#include "list.h"
#include <stdlib.h>

int ListOccorrenze(const Item* i, const ElemType* e) {
	if (ListIsEmpty(i)) {
		return 0;
	}

	int occ = 0;

	while (!ListIsEmpty(i)) {
		const ElemType* c = ListGetHeadValue(i);
		if (ElemCompare(c, e) == 0) {
			occ++;
		}

		i = ListGetTail(i);
	}

	return occ;
}

int main(void) {

	Item* list_A = NULL;
	Item* list_B = NULL;

	const ElemType ese_A[] = { 1, 2, 3, 3, 5, 6, 7 };
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	const ElemType BB = 23;

	int res = ListOccorrenze(list_A, ese_A + 1);
	res = ListOccorrenze(list_A, ese_A + 2);
	res = ListOccorrenze(list_A, &BB);
	res = ListOccorrenze(list_B, &BB);

	ListDelete(list_A);
	ListDelete(list_B);

	return 0;
}