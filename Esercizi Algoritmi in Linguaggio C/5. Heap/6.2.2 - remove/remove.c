#include "minheap.h"
#include <stdlib.h>

void DeleteNode(Heap* h, int k) {
	if (HeapIsEmpty(h)) {
		return;
	}

	if (k < 0 || k >= (int) h->size) {
		return;
	}

	ElemSwap(HeapGetNodeValue(h, k), HeapGetNodeValue(h, h->size - 1));
	ElemDelete(HeapGetNodeValue(h, h->size - 1));
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, k);
}

int main(void) {

	Heap* example_a = HeapCreateEmpty();
	ElemType a[] = { 1, 5, 4, 6, 12, 23 };
	size_t dim_a = sizeof(a) / sizeof(ElemType);
	for (size_t i = 0; i < dim_a; i++) {
		HeapMinInsertNode(example_a, &a[i]);
	}
	DeleteNode(example_a, 1);
	DeleteNode(example_a, 0);

	Heap* example_b = HeapCreateEmpty();
	ElemType b[] = { 1, 3, 2, 4, 5, 6, 7 };
	size_t dim_b = sizeof(b) / sizeof(ElemType);
	for (size_t i = 0; i < dim_b; i++) {
		HeapMinInsertNode(example_b, &b[i]);
	}
	DeleteNode(example_b, 2);

	Heap* example_c = HeapCreateEmpty();
	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	for (size_t i = 0; i < dim_c; i++) {
		HeapMinInsertNode(example_c, c + i);
	}
	DeleteNode(example_c, 5);

	HeapDelete(example_a);
	HeapDelete(example_b);
	HeapDelete(example_c);

	return 0;
}