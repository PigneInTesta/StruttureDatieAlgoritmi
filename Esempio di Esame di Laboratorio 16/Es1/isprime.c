#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool IsPrimeRec(int n, int i) {

	if (i == n - 1) {
		return true;
	}

	if (n % i == 0) {
		return false;
	}

	return IsPrimeRec(n, i + 1);
}

void IsPrime(int n) {
	if (n < 2) {
		printf("false");
		return;
	}

	if (n == 2) {
		printf("true");
		return;
	}

	if (IsPrimeRec(n, 2)) {
		printf("true");
		return;
	} else {
		printf("false");
		return;
	}
}

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	if (argc != 2 || n < 0) {
		return 1;
	}

	IsPrime(n);

	return 0;
}