// m sono i km totali da percorrere, d è l'array contenente le distanze tra stazioni, p è l'array contenente i prezzi delle stazioni e
// n è il numero di stazioni di servizio

#include <stdlib.h>
#include <stdio.h>

#define DOUBLE_MAX 1000000

typedef struct {
	double costo;		//ammontare della spesa
	int stazioni[];		// lista delle fermate
} piano;

void StazioniServizioRec(double m, const double* d, const double* p, size_t n, piano curr, piano *best, int i, double distcurr, double PercorsoDaUltimoRifornimento) {
	
	if (i == n) {
		if (curr.costo < best->costo) {
			best->costo = curr.costo;
			for (size_t i = 0; i < n; i++) {
				best->stazioni[i] = curr.stazioni[i];
			}
		}
		return;
	}

	distcurr += d[i];
	PercorsoDaUltimoRifornimento += d[i];

	if (PercorsoDaUltimoRifornimento > 600) {
		return;
	}

	curr.stazioni[i] = 0;
	StazioniServizioRec(m, d, p, n, curr, best, i + 1, distcurr, PercorsoDaUltimoRifornimento);

	curr.costo += PercorsoDaUltimoRifornimento * 0.05 * p[i];
	curr.stazioni[i] = 1;
	PercorsoDaUltimoRifornimento = 0;
	StazioniServizioRec(m, d, p, n, curr, best, i + 1, distcurr, PercorsoDaUltimoRifornimento);
}

void StazioniServizio(double m, const double* d, const double* p, size_t n) {

	piano curr, best;
	for (size_t i = 0; i < n; i++) {
		curr.stazioni[i] = 0;
		best.stazioni[i] = 0;
	}
	curr.costo = 0;
	best.costo = DOUBLE_MAX;

	StazioniServizioRec(m, d, p, n, curr, &best, 0, 0, 0);

	if (best.costo == DOUBLE_MAX) {
		printf("\nNon esistono soluzioni");
	} else {
		for (size_t i = 0; i < n; i++) {
			if (best.stazioni[i] == 1) {
				printf("%d ", i);
			}
			printf("\nSpesa totale: %f euro", best.costo);
		}
	}
}

int main() {

	double* dist = malloc(5 * sizeof(double));
	double* prezzi = malloc(5 * sizeof(double));

	for (int i = 0; i < 5; i++) {
		dist[i] = 260 + i * 24;
		prezzi[i] = i + 35 - i * i;
	}
	
	StazioniServizio(1540, dist, prezzi, 5);
}