#include "secanti.h"

double funz(const Polinomio* p, double x0, double x1) {
	
	double den1 = 0, den2 = 0;
	for (size_t i = 0; i < p->size; ++i) {
		den1 += p->coeffs[i] * pow(x1, i);
	}
	for (size_t j = 0; j < p->size; ++j) {
		den2 += p->coeffs[j] * pow(x0, j);
	}
	double xn_1 = x1 - ((x1 - x0) / (den1 - den2)) * den1;

	return xn_1;
}

double SecantiRec(const Polinomio* p, double xn_1, double xn, double t, int max_iter) {
	double xnp1 = funz(p, xn_1, xn);

	if (fabs(xnp1 - xn) <= t) {
		return xnp1;
	}

	if (max_iter == 1) {
		return xnp1;
	}

	return SecantiRec(p, xn, xnp1, t, max_iter - 1);
}

double Secanti(const Polinomio* p, double x0, double x1, double t, int max_iter) {

	return SecantiRec(p, x0, x1, t, max_iter);
}