#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void SubsetKRec(int n, int k, bool *vcurr, int i, int *nsol) {

	// caso base, sono ad un nodo terminale dello spazio delle soluzioni
	if (i == n) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			if (vcurr[j]) {
				cnt++;
			}
		}

		if (cnt == k) {
			(*nsol)++;
			printf("{ ");
			for (int j = 0; j < n; ++j) {
				if (vcurr[j]) {
					printf("%i ", j);
				}
			}
			printf("}, ");
		}

		return;
	}

	vcurr[i] = 0; // non prendo l'elemento i-esimo per costruire il sottoinsieme
	// i++ qui non va bene, perchè concettualmente non sto cambiando il livello del nodo
	SubsetKRec(n, k, vcurr, i + 1, nsol); // senza &, perchè è gia l'indirizzo di una variabile

	vcurr[i] = 1;
	SubsetKRec(n, k, vcurr, i + 1, nsol);
}

int SubsetK(int n, int k) {
	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;

	SubsetKRec(n, k, vcurr, 0, &nsol);

	free(vcurr);
	return nsol;
}

int main(void) {
	int nsol = SubsetK(4, 2);
	return 0;
}