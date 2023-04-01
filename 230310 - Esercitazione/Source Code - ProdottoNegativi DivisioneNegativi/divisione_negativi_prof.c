#include "fdi_check.h"

#include <limits.h>

int DivisioneNegativiRec(int a, int b) {
	// Caso base
	if (abs(a) < abs(b)) {
		return 0;
	}

	if (a * b >= 0) {
		return 1 + DivisioneNegativiRec(a - b, b);
	}
	else {
		return -1 + DivisioneNegativiRec(a + b, b);
	}
}


int DivisioneNegativi(int a, int b) {
	if (b == 0) {
		return INT_MAX;
	}

	return DivisioneNegativiRec(a, b);
}