#include "maxheap.h"
#include <stdbool.h>

extern Heap* HeapMaxHeapify(const ElemType* v, size_t v_size);
extern bool HeapMaxPop(Heap* h, ElemType* e);
extern void HeapMaxHeapsort(Heap* h);

int main(void) {

	ElemType a[] = { 1, 3, 2, 6, 5, 7, 4, 3, 8};
	size_t dim_a = sizeof(a) / sizeof(ElemType);

	Heap* example_a = HeapMaxHeapify(a, dim_a);

	ElemType ret;
	bool res = HeapMaxPop(example_a, &ret);
	HeapMaxHeapsort(example_a);

	return 0;
}