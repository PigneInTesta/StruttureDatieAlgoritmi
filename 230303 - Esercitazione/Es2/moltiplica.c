#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	
	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: \" mul <a> <b>\" ");
		return 1;
	}

	printf("%d", (atoi(&argv[1][0]) * atoi(&argv[2][0])));
	return 0;
}