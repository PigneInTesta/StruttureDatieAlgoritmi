#include "get_pop.h"

ElemType* Get(const Heap *h) {
	if (h == NULL || HeapIsEmpty(h)) {
		return NULL;
	}

	return HeapGetNodeValue(h, 0);
}

void Pop(Heap* h) {
	if (h == NULL || HeapIsEmpty(h)) {
		return;
	}

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
	ElemDelete(HeapGetNodeValue(h, h->size - 1));
	h->size--;
	h->data = realloc(h->data, h->size * sizeof(ElemType));
	HeapMinMoveDown(h, 0);
}