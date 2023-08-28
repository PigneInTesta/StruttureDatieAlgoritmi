#include "concatena.h"
#include "list.h"

int main(void) {

	Item* list_A = NULL;

	const ElemType ese_A[] = { 1, 2, 3, 4};
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	Item* list_B = NULL;

	const ElemType ese_B[] = { 5, 6, 7, 8 };
	size_t dim_B = sizeof(ese_B) / sizeof(ElemType);
	for (size_t i = 0; i < dim_B; i++) {
		list_B = ListInsertBack(list_B, ese_B + i);
	}

	Item* list_C = NULL;
	
	Item* list_D = NULL;

	Item* res_1 = Concatena(list_A, list_B, kCopy);
	Item* res_2 = Concatena(list_A, list_B, kNoCopy);
	Item* res_3 = Concatena(list_C, list_A, kCopy);
	Item* res_4 = Concatena(list_C, list_A, kNoCopy);
	Item* res_5 = Concatena(list_A, list_C, kNoCopy);
	Item* res_6 = Concatena(list_D, list_C, kNoCopy);

	ListDelete(res_1);
	ListDelete(res_2);
	ListDelete(res_3);

	return 0;
}