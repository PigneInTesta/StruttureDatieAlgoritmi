#include "minheap.h"
#include <stdlib.h>

Heap* HeapMerge(const Heap* h1, const Heap* h2) { 

	Heap* res = HeapCreateEmpty();

	if (h1) {
		for (size_t i = 0; i < h1->size; i++) {
			HeapMinInsertNode(res, HeapGetNodeValue(h1, i));
		}
	}

	if (h2) {
		for (size_t j = 0; j < h2->size; j++) {
			HeapMinInsertNode(res, HeapGetNodeValue(h2, j));
		}
	}

	return res;
}

int main(void) {

	Heap* Heap_A = HeapCreateEmpty();
	ElemType a[] = { 1, 5, 4, 6, 12, 23 };
	size_t dim_A = sizeof(a) / sizeof(ElemType);
	for (size_t i = 0; i < dim_A; i++) {
		HeapMinInsertNode(Heap_A, &a[i]);
	}

	Heap* Heap_C = HeapCreateEmpty();
	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
	size_t dim_C = sizeof(c) / sizeof(ElemType);
	for (size_t i = 0; i < dim_C; i++) {
		HeapMinInsertNode(Heap_C, c + i);
	}

	Heap* res = HeapMerge(Heap_A, Heap_C);
	HeapDelete(res);

	res = HeapMerge(NULL, Heap_C);
	HeapDelete(res);

	res = HeapMerge(HeapCreateEmpty(), Heap_C);
	HeapDelete(res);

	res = HeapMerge(HeapCreateEmpty(), HeapCreateEmpty());
	HeapDelete(res);

	HeapDelete(Heap_A);
	HeapDelete(Heap_C);

	return 0;
}