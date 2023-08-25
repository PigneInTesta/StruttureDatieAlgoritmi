#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void SubsetEqualRec(int n, int s, int i, int sum, bool* vcurr, int* nsol) {
	
	// Caso base: ho raggiunto la somma
	if (sum == s) {
		// Aumento il numero dei sottoinsiemi trovati
		(*nsol)++;

		// Stampa della soluzione corrente secondo il formato richiesto...
		printf("{ ");
		for (int j = 1; j <= n; j++) {
			if (vcurr[j]) {
				printf("%d ", j);
			}
		}
		printf("}, ");
		
		return;
	} 

	if (i > n) {
		return;
	}

	for (int e = i; e <= n; e++) {

		if (sum + e <= s) {
			vcurr[e] = true;

			SubsetEqualRec(n, s, e + 1, sum + e, vcurr, nsol);

			vcurr[e] = false;
		}
	}
}

int SubsetEqual(int n, int s) {
	// Verifica dei casi particolari
	if (n <= 0 || s <= 0) {
		return 0;
	}

	// Allocazione della memoria
	bool* vcurr = calloc(n + 1, sizeof(int));

	int nsol = 0;

	// Chiamata alla funzione di backtracking (a partire da i = 0)
	SubsetEqualRec(n, s, 1, 0, vcurr, &nsol);

	// Deallocazione della memoria
	free(vcurr);

	// Ritorno il numero di sottoinsiemi trovati
	return nsol;
}

int main(void) {

	int res;

	res = SubsetEqual(-1, -1);
	res = SubsetEqual(0, 0);
	res = SubsetEqual(4, 6);

	return 0;
 }