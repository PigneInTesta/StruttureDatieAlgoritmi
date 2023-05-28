#include "maxheap.h"
#include <stdlib.h>

void HeapMaxHeapsort(Heap* h) {
	ElemType* min = malloc(sizeof(ElemType));
	*min = INT_MAX;
	int min_pos = 0, cur = 0;

	for (int i = h->size - 1; i > 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (ElemCompare(&h->data[i - j + cur], min) < 0) {
				*min = h->data[i - j + cur];
				min_pos = i - j + cur;
			}
		}
		ElemSwap(&h->data[min_pos], &h->data[h->size - 1 - i]);
		*min = INT_MAX;
		cur++;
	}

	free(min);
}
