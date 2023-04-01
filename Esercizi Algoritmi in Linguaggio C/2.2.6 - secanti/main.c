#include "secanti.h"

int main(void) {

	Polinomio funzione = { .coeffs = NULL, .size = 4 };
	int c_funz[] = { 1, -12, -3, 2 };
	funzione.coeffs = c_funz;

	double res = Secanti(&funzione, -2, 4, 0.00001, -1);

	return 0;
}