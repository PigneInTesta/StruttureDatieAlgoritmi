#include "torrecartoni.h"

static bool IsInVcurr(int* vcurr, int j, int size) {
	for (int i = 0; i < size; i++) {
		if (vcurr[i] == j) {
			return true;
		}
	}
	return false;
}

static void TorreCartoniRec(const Cartone* c, size_t n, size_t i, int* vcurr, int* vbest, unsigned sum, unsigned hcurr, unsigned *hbest, int *max) {

	if (i == n) {
		for (size_t j = 0; j < n; j++) {		// questo ciclo va fuori dalla soluzione
			sum += c[vcurr[j]].p;				//
			hcurr += c[vcurr[j]].a;				//
			if (c[vcurr[j + 1]].l < sum) {		//
				for (size_t k = 0; k < j; k++) {				//usare memcpy anzichè il ciclo for
					(*max)++;
					if (hcurr > (*hbest) || (*hbest) == 0) {	//non ci va il >= perchè sarebbe già una soluzione migliore
						(*hbest) = hcurr;
						vbest[k] = vcurr[k];					
					}
				}
				sum = 0;
				hcurr = 0;
				break;
			}
			
		}
		return;
	}


	for (size_t j = 0; j < n; j++) {
		if (!IsInVcurr(vcurr, j, i)) {
			vcurr[i] = j;
			TorreCartoniRec(c, n, i + 1, vcurr, vbest, sum, hcurr, hbest, max);
		}
	}
}


void TorreCartoni(const Cartone* c, size_t n) {

	int* vcurr = calloc(n, sizeof(int));
	int* vbest = calloc(n, sizeof(int));
	int max = 0;
	unsigned hbest = 0;

	TorreCartoniRec(c, n, 0, vcurr, vbest, 0, 0, &hbest, &max);

	if (hbest != 0) {
		vbest = realloc(vbest, (max) * sizeof(int));			//Evitare di usare realloc
		for (int i = max - 1; i >= 0; i--) {
			printf("%d\n", vbest[i]);
			if (i == 0) {
				printf("Altezza: %d cm", hbest);
			}
		}
	}
	
 	free(vcurr);
	free(vbest);
}