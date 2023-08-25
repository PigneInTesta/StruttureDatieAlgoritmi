#ifndef NEWTON_H_
#define NEWTON_H_

#include <stdlib.h>
#include <math.h>

typedef struct {
	int* coeffs;
	size_t size;
} Polinomio;

extern double Newton(const Polinomio* p, const Polinomio* d, double xn, double t, int max_iter);

#endif /* NEWTON_H_ */