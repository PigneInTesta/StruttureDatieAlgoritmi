#include "minheap.h"
#include <stdlib.h>

bool HeapMinPop(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = *HeapGetNodeValue(h, 0);
	ElemDelete(&h->data[0]);
	h->data[0] = h->data[h->size - 1];
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	HeapMinMoveDown(h, 0);

	return true;
}
/*
int main(void) {

	Heap* example_a = HeapCreateEmpty();
	ElemType a[] = { 1, 5, 4, 6, 12, 23};
	size_t dim_a = sizeof(a) / sizeof(ElemType);
	for (size_t i = 0; i < dim_a; i++) {
		HeapMinInsertNode(example_a, &a[i]);
	}
	
	Heap* example_b = HeapCreateEmpty();
	ElemType b[] = { 1, 3, 2, 4, 5, 6, 7};
	size_t dim_b = sizeof(b) / sizeof(ElemType);
	for (size_t i = 0; i < dim_b; i++) {
		HeapMinInsertNode(example_b, &b[i]);
	}

	ElemType PopItem;
	bool res = HeapMinPop(example_a, &PopItem);
	res = HeapMinPop(example_b, &PopItem);

	return 0;
}
*/