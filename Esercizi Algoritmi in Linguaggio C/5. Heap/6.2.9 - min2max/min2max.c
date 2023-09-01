#include "minheap.h"

void HeapMaxMoveDown(Heap* h, int i) {
	int l, r, biggest = i;
	bool done;
	do {
		done = true;
		l = HeapLeft(i);
		r = HeapRight(i);

		if ((l < (int)h->size) && ElemCompare(HeapGetNodeValue(h, l), HeapGetNodeValue(h, biggest)) > 0) {
			biggest = l;
		}

		if ((r < (int)h->size) && ElemCompare(HeapGetNodeValue(h, r), HeapGetNodeValue(h, biggest)) > 0) {
			biggest = r;
		}

		if (biggest != i) {
			ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, biggest));
			i = biggest;
			done = false;
		}

	} while (!done);
}

void HeapMin2Max(Heap* h) {
	if (!h || HeapIsEmpty(h)) {
		return;
	}

	for (int i = (int) h->size / 2 - 1; i >= 0; i--) {
		HeapMaxMoveDown(h, i);
	}
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

	HeapMin2Max(Heap_A);
	HeapMin2Max(Heap_C);

	HeapDelete(Heap_A);
	HeapDelete(Heap_C);

	return 0;
}