#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

static bool IsInList(Item **list, int size, const Item *tocheck) {
	for (int d = 0; d < size; d++) {
		if (*(list + d) == tocheck) {
			return true;
		}
	}

	return false;
}

bool AnyLoop(const Item* i) {
	if (ListIsEmpty(i)) {
		return false;
	}

	const Item* tmp = i;
	//Item* prev = ListCreateEmpty();

	Item** list = NULL;

	for (int j = 1; !ListIsEmpty(tmp); j++) {
		list = realloc((void*)list, j * sizeof(Item*));

		if (!IsInList(list, j, tmp)) {
			*(list + j - 1) = tmp;
		} else {
			return true;
		}
		
		tmp = ListGetTail(tmp);
	}

	return false;
}

int main(void) {

	Item* list_A = ListCreateEmpty();
	Item* list_B = ListCreateEmpty();

	const ElemType ese_A[] = { 12, 99, 37, 37};
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	list_A->next->next->next->next = list_A->next->next;

	bool state = AnyLoop(list_A);
	state = AnyLoop(list_B);

	return 0;
}