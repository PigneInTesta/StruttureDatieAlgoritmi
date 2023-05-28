#include "minheap.h"
#include <stdlib.h>

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		return HeapCreateEmpty();
	}

	Heap* res = HeapCreateEmpty();
	for (size_t i = 0; i < v_size; i++) {
		if (i == 0) {
			HeapMinInsertNode(res, &v[i]);
		}
		
		if (HeapLeft(i) < (int) v_size) {
			HeapMinInsertNode(res, &v[HeapLeft(i)]);
		}

		if (HeapRight(i) < (int) v_size) {
			HeapMinInsertNode(res, &v[HeapRight(i)]);
		}
		
	}

	return res;
}

int main(void) {

	ElemType a[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

	size_t dim_a = sizeof(a) / sizeof(ElemType);

	Heap* res_a = HeapMinHeapify(a, dim_a);

	return 0;
}
