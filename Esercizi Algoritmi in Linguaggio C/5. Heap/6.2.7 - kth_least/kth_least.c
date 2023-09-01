#include "minheap.h"
#include <stdlib.h>

ElemType KthLeast(const Heap* h, int k) {

	Heap* copy = malloc(sizeof(Heap));
	copy->size = h->size;
	copy->data = malloc(copy->size * sizeof(ElemType));
	for (size_t j = 0; j < copy->size; j++) {
		copy->data[j] = ElemCopy(HeapGetNodeValue(h, j));
	}

	size_t origin_size = copy->size;
	while (--k > 0) {
		ElemSwap(HeapGetNodeValue(copy, 0), HeapGetNodeValue(copy, copy->size - 1));
		copy->size--;
		HeapMinMoveDown(copy, 0);
	}

	ElemType res = ElemCopy(HeapGetNodeValue(copy, 0));
	copy->size = origin_size;

	HeapDelete(copy);
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

	ElemType res = KthLeast(Heap_A, 2);
	res = KthLeast(Heap_C, 5);

	HeapDelete(Heap_A);
	HeapDelete(Heap_C);
	
	return 0;
}