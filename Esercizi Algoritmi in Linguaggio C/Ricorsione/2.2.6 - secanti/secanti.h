#ifndef SECANTI_H_
#define SECANTI_H_

#include <stdlib.h>
#include <math.h>

typedef struct {
	int* coeffs;
	size_t size;
}Polinomio;

extern double Secanti(const Polinomio* p, double x0, double x1, double t, int max_iter);

#endif /* SECANTI_H_ */