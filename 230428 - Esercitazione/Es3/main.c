#include "vettore.h"

int main(void) {

	Vector A = { .capacity = 10, .size = 10, .data = NULL };
	ElemType dati[] = { -2, 1, 3, 3, 4, 4, 4, 5, 12, 34 };
	A.data = dati;

	ElemType number = 4;
	int res = VectorFind(&A, &number);
	return 0;
}