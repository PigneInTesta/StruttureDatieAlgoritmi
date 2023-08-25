#include <math.h>
#include <float.h>

double SenRec(double x, int i, int n, double fact) {

	if (n == i) {
		return fact;
	}

	fact += (pow(-1, n) / tgamma((2 * n + 1) + 1)) * pow(x, 2 * n + 1);

	return SenRec(x, i, n + 1, fact);
}

double Sen(double x, int i) {

	if (i < 0) {
		return DBL_MIN;
	}

	return SenRec(x, i, 0, 0);
}

int main(void) {

	double res = Sen(1.5708, -1);
	res = Sen(1.5708, 5);
	res = Sen(0, 1);

	return 0;
}