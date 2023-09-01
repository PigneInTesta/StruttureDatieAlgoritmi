#include "minheap.h"
#include <stdlib.h>

//Al termine dell'esecuzione il nostro min-heap non è più da considerare tale perchè non rispetta le proprietà

void HeapMinHeapsort(Heap* h) {
	if (h == NULL) {
		return;
	}

	size_t origin_size = h->size;

	while (h->size > 1) {
		ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));
		h->size--;
		HeapMinMoveDown(h, 0);
	}

	h->size = origin_size;
}

int main(void) {

	Heap* res_c = HeapCreateEmpty();
	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	for (size_t i = 0; i < dim_c; i++) {
		HeapMinInsertNode(res_c, c + i);
	}

	HeapMinHeapsort(res_c);
	HeapMinHeapsort(NULL);

	HeapDelete(res_c);

	return 0;
}