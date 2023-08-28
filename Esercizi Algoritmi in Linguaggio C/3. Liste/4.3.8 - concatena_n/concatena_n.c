#include "list.h"
#include <stdlib.h>
#include <stdbool.h>

Item* ConcatenaN(Item** v, size_t v_size) {
	if (v_size == 0) {
		return ListCreateEmpty();
	} else {
		size_t cnt = 0;
		for (size_t i = 0; i < v_size; i++) {
			if (ListIsEmpty(*(v + i))) {
				cnt++;
			}
		}
		if (cnt == v_size) {
			return ListCreateEmpty();
		}
	}

	Item fake_head;
	bool head = false;
	Item* prev = *(v + 0);

	for (size_t k = 0; k < v_size; k++) {

		if (head) {
			prev->next = *(v + k);
		}

		if (!ListIsEmpty(*(v + k)) && !head) {			//Individuo la prima lista che sarà la mia testa
			fake_head.next = *(v + k);
			prev = *(v + k);
			head = true;
		} else if (!head) {
			continue;
		}

		while (!ListIsEmpty(*(v + k))) {
			prev = *(v + k);
			*(v + k) = ListGetTail(*(v + k));
		}
	}

	return fake_head.next;
}

//int main(void) {
//
//	Item** v_A = malloc(3 * sizeof(Item));
//	Item** v_B = malloc(3 * sizeof(Item));
//
//	for (int i = 0; i < 3; i++) {
//		*(v_A + i) = ListCreateEmpty();
//		*(v_B + i) = ListCreateEmpty();
//	}
//
//	ElemType ese_v[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
//	size_t dim_ese_v = sizeof(ese_v) / sizeof(ElemType);
//
//	for (size_t i = 0; i < dim_ese_v; i++) {
//		if (i < 5 || i >= 10) {
//			*(v_A + i / 5) = ListInsertBack(*(v_A + i / 5), ese_v + i);
//		}
//	}
//
//	Item* res_A = ConcatenaN(v_A, dim_ese_v / 5);
//	Item* res_B = ConcatenaN(v_B, dim_ese_v / 5);
//
//	ListDelete(res_A);
//	ListDelete(res_B);
//
//	ElemDelete(ese_v);
//
//	return 0;
//}