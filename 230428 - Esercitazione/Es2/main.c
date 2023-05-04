#include "vettore.h"

int main(void) {

	Vector res = { .capacity = 10, .size = 10, .data = NULL };
	ElemType A[] = { 4, 34, 12, -2, 3, 4, 5, 1, 3, 4 };
	res.data = A;
	VectorSort(&res);
	VectorSort(NULL);

	return 0;
}