#include "newton.h"

int main(void) {

	Polinomio funzione = { .coeffs = NULL, .size = 4 };
	int c_funz[] = { 0, -2, 0, 1 };
	funzione.coeffs = c_funz;

	Polinomio derivata = { .coeffs = NULL, .size = 3 };
	int c_der[] = { -2, 0, 3 };
	derivata.coeffs = c_der;

	double res = Newton(&funzione, &derivata, 5, 0.0000001, 20);

	return 0;
}