#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void FindSetsRec(int* subset1, int* subset2, int* numbers, size_t n, bool *vcurr, bool *vbest, int i, int cnt, int sum1, int sum2, int diff_curr, int* diff_best) {

	//Faccio il totale di ogni singolo sottoinsieme
	for (size_t f = 0, flag1 = 0, flag2 = 0; f < n; f++) {
		if (vcurr[f]) {
			sum1 += numbers[f];
			subset1[flag1] = numbers[f];
			flag1++;
		}
		else {
			sum2 += numbers[f];
			subset2[flag2] = numbers[f];
			flag2++;
		}
	}
	//Verifichiamo le differenze tra i due sottoinsiemi
	diff_curr = abs(sum1 - sum2);

	if (diff_curr < diff_best || diff_best == 0) {
		diff_best = diff_curr;
	}

	vcurr[i] = 0;
	FindSetsRec(subset1, subset2, n, vcurr, vbest, i + 1, cnt, sum1, sum2, diff_curr, diff_best);
	
	vcurr[i] = 1;
	FindSetsRec(subset1, subset2, n, vcurr, vbest, i + 1, cnt + 1, sum1, sum2, diff_curr, diff_best);

}

void FindSets(int* numbers, size_t n) {
	int* A = calloc(n / 2, sizeof(int));				//sottoinsieme di dimensione n/2
	int* B = calloc(n - n / 2, sizeof(int));			//sottoinsieme di dimensione n - n/2
	bool* vcurr = calloc(n, sizeof(bool));				//max 2 scelte per ogni soluzione parziale
	bool* vbest = calloc(n, sizeof(bool));				
	int diff_best = 0;

	FindSetsRec(A, B, numbers, n, vcurr, vbest, 0, 0, 0, 0, 0, &diff_best);

	//Stampa a video dei due sottoinsiemi
	for (size_t x = 0; x < n / 2; x++) {
		if (x == 0) {
			putchar('\{');
			printf(" %d", A[x]);
		} else if (x < n / 2) {
			printf(", %d", A[x]);
		} else {
			putchar('\}, ');
		}
	}

	for (size_t t = 0; t < n - n / 2; t++) {
		if (t == 0) {
			putchar('\{');
			printf(" %d", B[t]);
		} else if (t < n - n / 2) {
			printf(", %d", B[t]);
		} else {
			putchar('\}');
		}
	}
}

//Funzione che converte i numeri passati tramite linea di comando
int* CharToInt(const char* ptr, int* num, size_t n) {
	int cnt = 0, i = 0;

	while (cnt != n) {
		if (ptr[i] != '\0') {
			num[cnt] = atoi(&ptr[i]);
			cnt++;
			i++;
		}
		i++;
	}

	return num;
}

int main(int argc, char* argv[]) {

	size_t n = argc - 1;
	int* num = calloc(n, sizeof(int));					//array che contiene i numeri passati tramite linea di comando
	num = CharToInt(argv[1], num, n);
	
	FindSets(num, n);

	return 0;
}