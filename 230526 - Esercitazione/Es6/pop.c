#include "maxheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool HeapMaxPop(Heap* h, ElemType* e) {
	if (HeapIsEmpty(h)) {
		return false;
	}

	*e = *HeapGetNodeValue(h, 0);
	ElemDelete(&h->data[0]);
	h->data[0] = h->data[h->size - 1];
	h->size--;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);

	HeapMaxMoveDown(h, 0);

	return true;
}