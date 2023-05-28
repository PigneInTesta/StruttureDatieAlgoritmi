#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {
	if (i == 0) {
		return;
	}

	if (ElemCompare(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i))) < 0) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
	}

	HeapMinMoveUpRec(h, HeapParent(i));
}
/*
int main(void) {

	Heap* example_a = HeapCreateEmpty();
	ElemType a[] = { 1, 3, 2, 6, 5, 7, 4, 3, 8 };
	size_t dim_a = sizeof(a) / sizeof(ElemType);
	for(size_t i = 0; i < dim_a; i++){
		HeapMinInsertNode(example_a, &a[i]);
	}

	HeapMinMoveUpRec(example_a, 7);

	return 0;
}
*/