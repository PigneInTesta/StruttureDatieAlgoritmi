#include <limits.h>
extern int DivisioneNegativi(int a, int b);

int DivisioneNegativiRec(int a, int b, int i) {
	
	if ((a - b) >= 0) {	// Divisione tra con a e b > 0
		i++;
		return DivisioneNegativiRec(a - b, b, i);
	} else if (a < 0 && (((-a) - b) >= 0)) { // Divisone con a < 0 e b > 0 ma con |a| > b
		i--;
		return DivisioneNegativiRec(a + b, b, i);
	} else if (a > 0 && (a - (-b)) >= 0) {	// Divisone con a > 0 e b < 0 con a > |b|
		i--;
		return DivisioneNegativiRec(a + b, b, i);
	}
	
	return i;
}

int DivisioneNegativi(int a, int b) {

	if (b == 0) {
		return INT_MAX;
	}

	DivisioneNegativiRec(a, b, 0);
}

int main(void) {

	DivisioneNegativi(1, 1);
	DivisioneNegativi(1, -1);
	DivisioneNegativi(0, 0);
	DivisioneNegativi(6, 0);
	DivisioneNegativi(0, -6);
	DivisioneNegativi(-6, -3);
	DivisioneNegativi(-4, 2);
	DivisioneNegativi(3, 2);
	DivisioneNegativi(7, 3);
	DivisioneNegativi(3, 6);
	DivisioneNegativi(7, 3);

	return 0;
}
