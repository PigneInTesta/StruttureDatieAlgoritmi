#include "get_pop.h"

int main(void) {

	Heap* res_c = HeapCreateEmpty();
	ElemType c[] = { 0, 12, 4, 21, 2, 18, 77, 8, 9 };	//non è ancora una min-heap
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	for (size_t i = 0; i < dim_c; i++) {
		HeapMinInsertNode(res_c, c + i);
	}

	ElemType* res = Get(res_c);
	Pop(res_c);

	HeapDelete(res_c);

	return 0;
}