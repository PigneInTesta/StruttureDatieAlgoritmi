#include "minheap.h"
#include <stdlib.h>
#include <string.h>

Heap* HeapCopy(const Heap* h) {
	if (h == NULL) {
		return NULL;
	}
	if (HeapIsEmpty(h)) {
		return HeapCreateEmpty();
	}

	Heap* res = malloc(sizeof(Heap));
	res->size = h->size;
	res->data = malloc(res->size * sizeof(ElemType));
	//memcpy(res->data, h->data, res->size * sizeof(ElemType));  non va bene perchè produrebbe una copia superficiale dei dati
	for (size_t i = 0; i < res->size; i++) {
		res->data[i] = ElemCopy(h->data + i);
	}

	return res;
}

int main(void) {

	Heap* res_c = HeapCreateEmpty();
	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	for (size_t i = 0; i < dim_c; i++) {
		HeapMinInsertNode(res_c, c + i);
	}

	Heap* res = HeapCopy(res_c);
	HeapDelete(res);

	res = HeapCopy(NULL);

	res = HeapCopy(HeapCreateEmpty());
	HeapDelete(res);
	
	HeapDelete(res_c);

	return 0;
}