#include <stdlib.h>
#include <stdio.h>

void BacktrackStrModRec(int n, int k, int i, char* vcurr) {
	// Caso base: stringa di n caratteri
	if (i == k) {
		// Stampa della soluzione corrente secondo il formato richiesto...
		printf("{ ");
		for (int j = 0; j < k; j++) {
			printf("%c", vcurr[j]);
		}
		printf(" }, ");
		return;
	}

	for (char c = 'a'; c < 'a' + n; c++) {
		vcurr[i] = c;

		BacktrackStrModRec(n, k, i + 1, vcurr);
	}
}

void BacktrackStrMod(int n, int k) {
	// Verifica dei casi particolari
	if (k <= 0 || k > 26 || n <= 0) {
		return;
	}

	// Allocazione della memoria
	char* vcurr = malloc(n);

	// Chiamata alla funzione di backtracking (a partire da i = 0)
	BacktrackStrModRec(n, k, 0, vcurr);

	//Deallocazione della memoria
	free(vcurr);
}

int main(void) {

	BacktrackStrMod(-1, -1);
	puts("");
	BacktrackStrMod(0, 0);
	puts("");
	BacktrackStrMod(1, 1);
	puts("");
	BacktrackStrMod(2, 2);
	puts("");
	BacktrackStrMod(3, 2);
	puts("");

	return 0;
}