#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {

	if (i > (int)(h->size - 1) / 2) {
		return;
	}

	size_t left = HeapLeft(i);
	size_t right = HeapRight(i);
	size_t smallest = i;

	if (left < h->size && ElemCompare(HeapGetNodeValue(h, left), HeapGetNodeValue(h, smallest)) < 0) {
		smallest = left;
	}

	if (right < h->size && ElemCompare(HeapGetNodeValue(h, right), HeapGetNodeValue(h, smallest)) < 0) {
		smallest = right;
	}

	if (i != (int) smallest) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, smallest));
		HeapMinMoveDownRec(h, smallest);
	}
}
/*
int main(void) {

	Heap* example_a = HeapCreateEmpty();
	ElemType a[] = { 1, 3, 2, 15, 6, 5, 7, 4, 8 };
	size_t dim_a = sizeof(a) / sizeof(ElemType);
	example_a->data = a;
	example_a->size = dim_a;

	HeapMinMoveDownRec(example_a, 3);

	return 0;
}
*/