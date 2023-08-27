#include "list.h"
#include "vector_list.h"

int main(void) {

	Item* list_A = NULL;

	const ElemType ese_A[] = { 1, 2, 3, 4, 5, 6, 7 };
	size_t dim_A = sizeof(ese_A) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		list_A = ListInsertBack(list_A, ese_A + i);
	}

	Item* res_list_A = Vector2List(ese_A, dim_A, kInOrder);
	Item* res_list_B = Vector2List(ese_A, dim_A, kReverse);

	ListDelete(res_list_A);
	ListDelete(res_list_B);

	size_t dim_elem = 0;

	ElemType* res_elem = List2Vector(list_A, &dim_elem, kInOrder);
	dim_elem = 0;
	res_elem = List2Vector(list_A, &dim_elem, kReverse);

	ElemDelete(res_elem);

	return 0;
}