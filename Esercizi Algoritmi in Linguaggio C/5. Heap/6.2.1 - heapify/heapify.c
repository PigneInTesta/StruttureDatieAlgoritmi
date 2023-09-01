#include "minheap.h"
#include <stdlib.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return HeapCreateEmpty();
	}

	Heap* res = HeapCreateEmpty();

	for (size_t i = 0; i < v_size; i++) {
		if (i == 0) {
			HeapMinInsertNode(res, v + 0);
		}

		if (HeapLeft(i) < (int) v_size) {
			HeapMinInsertNode(res, v + HeapLeft(i));
		}

		if (HeapRight(i) < (int) v_size) {
			HeapMinInsertNode(res, v + HeapRight(i));
		}
	}

	return res;
}

int main(void) {

	ElemType a[] = { 1, 5, 4, 6, 12, 23 };
	size_t dim_a = sizeof(a) / sizeof(ElemType);
	Heap* res_a = HeapMinHeapify(a, dim_a);

	ElemType b[] = { 1, 3, 2, 4, 5, 6, 7 };
	size_t dim_b = sizeof(b) / sizeof(ElemType);
	Heap* res_b = HeapMinHeapify(b, dim_b);

	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9};
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	Heap* res_c1 = HeapMinHeapify(c, dim_c);
	Heap* res_c2 = HeapCreateEmpty();
	for (size_t i = 0; i < dim_c; i++) {
		HeapMinInsertNode(res_c2, c + i);
	}
	
	HeapDelete(res_a);
	HeapDelete(res_b);
	HeapDelete(res_c1);
	HeapDelete(res_c2);

	return 0;
}