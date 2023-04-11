#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int i, bool* vcurr, bool* vbest, int* max, int cnt, int sum) {
	//Sommiamo i pacchi presi in vcurr
	sum = 0;
	for (int j = 0; j < i; j++) {
		if (vcurr[j]) {
			sum += pacchi[j];
		}
	}
	//Pruning: se la somma supera la portata massima
	//della slitta oppure se il numero di pacchi presi
	//è minore di quello presente nella sol. migliore
	if (sum > p || cnt + (pacchi_size - i - 1) < *max) {
		return;
	}
	//Verifchiamo che sia veramente la soluzione migliore
	if (*max < cnt) {
		*max = 0;
		for (size_t w = 0; w < pacchi_size; w++) {
			vbest[w] = vcurr[w];
			if (vbest[w]) {
				(*max)++;
			}
		}
		return;
	}
	//Se abbiamo raggiunto la portata della slitta
	//aggiorniamo il vettore vbest
	if (sum == p) {
		*max = 0;
		for (size_t k = 0; k < pacchi_size; k++) {
			vbest[k] = vcurr[k];
			if (vbest[k] == 1) {
				(*max)++;
			}
		}
		return;
	}
	//Siamo arrivati alle foglie dell'albero
	//abbiamo trovato una possibile soluzione
	if (i == pacchi_size) {
		return;
	}

	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum);

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt + 1, sum);

	vcurr[i] = 0;
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* vbest = calloc(pacchi_size, sizeof(bool));
	int max = 0;

	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, &max, 0, 0);

	if (max != 0) {
		for (size_t i = 0; i < pacchi_size; i++) {
			printf("%d ", vbest[i]);
		}
	}

	free(vcurr);
	free(vbest);
}

int main(void) {

	int pacchi[] = { 10, 11, 1, 3, 3 };
	BabboNatale(pacchi, 5, 20);

	return 0;
}
