#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int DivisibilePerSette(int n) {
	if (n / 10 == 0) {
		return n;
	}

	return DivisibilePerSette(abs((n / 10) - (n % 10) * 2));
}

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	if (argc != 2 || n < 0) {
		return 1;
	}

	int res = DivisibilePerSette(n);

	if ( res == 7 || res == 0) {
		printf("Multiplo di 7.");
	} else {
		printf("Non multiplo di 7.");
	}

	return 0;
}