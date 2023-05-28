#include "maxheap.h"
#include <stdlib.h>

Heap* HeapMaxHeapify(const ElemType* v, size_t v_size) {
	if (v == NULL) {
		HeapCreateEmpty();
	}

	Heap* res = HeapCreateEmpty();

	for (size_t i = 0; i < v_size; i++) {
		HeapMaxInsertNode(res, &v[i]);
	}

	return res;
}