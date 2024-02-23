#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>

bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h)) {
		return false;
	}

	for (int i = 0; i < (int) h->size; i++) {
		if ((HeapLeft(HeapParent(i)) < (int)h->size) && ElemCompare(HeapGetNodeValue(h, HeapParent(i)), HeapGetNodeValue(h, HeapLeft(HeapParent(i)))) > 0) {
			return false;
		}
		if ((HeapRight(HeapParent(i)) < (int)h->size) && ElemCompare(HeapGetNodeValue(h, HeapParent(i)), HeapGetNodeValue(h, HeapRight(HeapParent(i)))) > 0) {
			return false;
		}
	}

	return true;
}


//int main(void) {
//
//	Heap* Heap_A = HeapCreateEmpty();
//	ElemType a[] = { 1, 5, 4, 6, 12, 23 };
//	size_t dim_A = sizeof(a) / sizeof(ElemType);
//	for (size_t i = 0; i < dim_A; i++) {
//		HeapMinInsertNode(Heap_A, &a[i]);
//	}
//
//	Heap* Heap_C = HeapCreateEmpty();
//	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
//	size_t dim_C = sizeof(c) / sizeof(ElemType);
//	for (size_t i = 0; i < dim_C; i++) {
//		HeapMinInsertNode(Heap_C, c + i);
//	}
//
//	Heap* Heap_D = HeapCreateEmpty();
//	for (size_t i = 0; i < dim_C; i++) {
//		Heap_D->size++;
//		Heap_D->data = realloc(Heap_D->data, sizeof(ElemType) * Heap_D->size);
//		Heap_D->data[Heap_D->size - 1] = ElemCopy(c + i);
//	}
//
//	bool state = IsHeap(Heap_A);	//true
//	state = IsHeap(Heap_C);			//true
//	state = IsHeap(Heap_D);			//false
//
//	HeapDelete(Heap_A);
//	HeapDelete(Heap_C);
//	HeapDelete(Heap_D);
//	return 0;
//}