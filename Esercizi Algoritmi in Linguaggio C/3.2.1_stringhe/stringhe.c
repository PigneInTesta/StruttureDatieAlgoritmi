#include <stdlib.h>
#include <stdio.h>

void BacktrackStrRec(int n, int i, char* vcurr) {
	// Caso base: stringa di n caratteri
	if (i == n) {
		// Stampa della soluzione corrente secondo il formato richiesto...
		printf("{ ");
		for (int j = 0; j < n; j++) {
			printf("%c", vcurr[j]);
		}
		printf(" }, ");
		return; // ... e terminazione della ricorsione.
	}

	// Se il vettore soluzione non è ancora completo aggiungo un nuovo carattere
	// scelto fra quelli ammissibili (ovviamente provandoli tutti)
	for (char c = 'a'; c < 'a' + n; c++) {
		// Scelta del carattere i-esimo (da 'a' ad 'a' + n)
		vcurr[i] = c;

		// Chiamata ricorsiva per la scelta (i + 1)-esima
		BacktrackStrRec(n, i + 1, vcurr);
	}
}

void BacktrackStr(int n) {
	// Verifica dei casi particolari
	if (n <= 0 || n > 26) {
		return;
	}

	// Allocazione della memoria
	char* vcurr = malloc(n);

	// Chiamata alla funzione di backtracking (a partire da i = 0)
	BacktrackStrRec(n, 0, vcurr);

	// Deallocazione della memoria
	free(vcurr);
}

int main(void) {
	BacktrackStr(-1);
	puts("");
	BacktrackStr(0);
	puts("");
	BacktrackStr(1);
	puts("");
	BacktrackStr(2);
	puts("");
	BacktrackStr(3);
	puts("");

	return 0;
}