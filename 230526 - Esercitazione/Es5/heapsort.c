#include "minheap.h"
#include <stdlib.h>
#include <limits.h>

void HeapMinHeapsort(Heap* h) {

	ElemType* max = malloc(sizeof(ElemType));
	int max_pos;
	
	for (size_t i = 0; i < h->size; i++) {
		for (size_t j = i; j < h->size; j++) {
			if (ElemCompare(&h->data[j], max) > 0) {
				*max = h->data[j];
				max_pos = j;
			}
		}
		ElemSwap(&h->data[max_pos], &h->data[i]);
		*max = INT_MIN;
	}

	free(max);
}

int main(void) {

	Heap* example_a = HeapCreateEmpty();
	ElemType a[] = { 1, 3, 2, 6, 5, 7, 4, 3, 8 };
	size_t dim_a = sizeof(a) / sizeof(ElemType);
	for (size_t i = 0; i < dim_a; i++) {
		HeapMinInsertNode(example_a, &a[i]);
	}

	Heap* example_b = HeapCreateEmpty();
	ElemType b[] = {0, 4, 3, 2};
	size_t dim_b = sizeof(b) / sizeof(ElemType);
	for (size_t i = 0; i < dim_b; i++) {
		HeapMinInsertNode(example_b, &b[i]);
	}

	HeapMinHeapsort(example_a);
	HeapMinHeapsort(example_b);
}
