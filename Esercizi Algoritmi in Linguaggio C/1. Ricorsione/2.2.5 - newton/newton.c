#include "newton.h"

double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter) {
	double funz = 0, der = 0;

	for (size_t j = 0; j < p->size; j++) {
		funz += p->coeffs[j] * pow(xn, j);
	}

	for (size_t k = 0; k < d->size; k++) {
		der += d->coeffs[k] * pow(xn, k);
	}

	double xn_1 = xn - funz / der;

	if (fabs(xn_1 - xn) <= t) {
		return xn_1;
	}

	if (max_iter == 1) {
		return xn_1;
	}

	return Newton(p, d, xn_1, t, max_iter - 1);
}