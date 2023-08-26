#include "list.h"
#include <stdlib.h>

int ListLength(const Item *i){
	if (ListIsEmpty(i)) {
		return 0;
	}

	int cnt = 0;

	while (!ListIsEmpty(i)) {
		cnt++;
		i = ListGetTail(i);
	}

	return cnt;
}

int ListLengthRec(const Item* i) {
	if (ListIsEmpty(i)) {
		return 0;
	}

	return ListLengthRec(ListGetTail(i)) + 1;
}

int main(void) {
	
	//da aggiungere nelle liste di esempio per l'esame
	Item* list_A = NULL;
	Item* list_B = NULL;

	const ElemType ese_A[] = { 1, 2, 3, 4, 5, 6, 7 };
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	int res = ListLength(list_A);
	res = ListLengthRec(list_A);
	res = ListLength(list_B);
	res = ListLengthRec(list_B);

	ListDelete(list_A);
	ListDelete(list_B);

	return 0;
}