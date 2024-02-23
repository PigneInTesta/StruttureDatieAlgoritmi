#include <stdio.h>
#include <stdlib.h>

int tnumbers(int n) {
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else if (n == 2) {
		return 3;
	}

	return 3 * tnumbers(n - 1) - 3 * tnumbers(n - 2) + tnumbers(n - 3);
}

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	if (argc != 2 || n < 0) {
		return 1;
	}

	printf("%d", tnumbers(n));
	return 0;
}