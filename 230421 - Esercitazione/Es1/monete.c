#include <stdlib.h>

int* Monete(const int* tagli, size_t tagli_size, int budget) {

	if (budget <= 0) {
		return NULL;
	}

	int* res = calloc(tagli_size, sizeof(int));

	for (size_t i = 0; i < tagli_size; i++) {
		if (budget >= tagli[i]) {
			res[i] = budget / tagli[i];
			budget %= tagli[i];
		}
	}

	return res;
}
/*
int main(void) {

	int tagli[] = { 50, 20, 10, 5, 2, 1 };
	int* res = Monete(tagli, 6, 126);

	return 0;
}
*/