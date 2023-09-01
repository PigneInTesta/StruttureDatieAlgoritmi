#include "minheap.h"
#include <stdlib.h>
#include <stdbool.h>

bool IsHeap(const Heap* h) {
	if (h == NULL) {
		return false;
	}
	if (HeapIsEmpty(h)) {
		return true;
	}

	for (size_t i = 0; i < h->size / 2 - 1; i++) {
		if (HeapLeft(i) < (int) h->size && ElemCompare(HeapGetNodeValue(h, HeapParent(HeapLeft(i))), HeapGetNodeValue(h, HeapLeft(i))) > 0) {
			return false;
		}

		if (HeapRight(i) < (int) h->size && ElemCompare(HeapGetNodeValue(h, HeapParent(HeapRight(i))), HeapGetNodeValue(h, HeapRight(i))) > 0) {
			return false;
		}
	}

	return true;

}

int main(void) {

	Heap* res_cv = HeapCreateEmpty();
	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	for (size_t i = 0; i < dim_c; i++) {
		HeapMinInsertNode(res_cv, c + i);
	}

	Heap* res_cf = HeapCreateEmpty();
	res_cf->size = dim_c;
	res_cf->data = realloc(res_cf->data, res_cf->size * sizeof(ElemType));
	for (size_t j = 0; j < dim_c; j++) {
		res_cf->data[j] = ElemCopy(c + j);
	}

	bool state = IsHeap(res_cv);
	state = IsHeap(res_cf);
	state = IsHeap(NULL);
	state = IsHeap(HeapCreateEmpty());

	HeapDelete(res_cv);
	HeapDelete(res_cf);

	return 0;
}