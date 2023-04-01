#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(int argc, char *argv[]) {

	int occ = 0;

	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \"occorrenze <s> <c>\" ", *argv);
		return 1;
	}

	for (int i = 1, j = 0; i < argc; ++i) {
		while (argv[1][j] != '\0') {
			if (argv[2][0] == argv[1][j]) {
				occ++;
			}
			j++;
		}
	}

	printf("%d", occ);

	return 0;
}