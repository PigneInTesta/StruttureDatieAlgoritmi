#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void RegoleRec(const char* r, int length, int i, int* vcurr, bool* usati) {

	if (i == length) {
		for (int j = 0; j < length; ++j) {
			printf("%d ", vcurr[j]);
		}
		puts("");
		return;
	}
	
	// Procedo ricorsivamente scegliendo a turno uno dei valori in [1, n + 1(length)]
	for (int t = 1; t <= length; ++t) {

		bool I = !usati[t - 1]; // Il valore t non è già stato usato nella sequenza
		bool a = i == 0;		// Stiamo scegliendo il primo elemento della nostra sequenza
		// La regola corrente è di incremento e il precedente è < t
		bool b = (r[i - 1] == 'i' || r[i - 1] == 'I') && vcurr[i - 1] < t;
		// La regola corrente è di decremento e il precedente è > t
		bool c = (r[i - 1] == 'd' || r[i - 1] == 'D') && vcurr[i - 1] > t;
		bool II = a || b || c;

		if (I && II) {
			usati[t - 1] = 1;
			vcurr[i] = t;
			RegoleRec(r, length, i + 1, vcurr, usati);
			usati[t - 1] = 0;
		}
	}

}

void Regole(const char* r) {
	// Verifica dei casi particolari
	if (r == "") {
		printf("1\n");
		return;
	}

	// Calcolo della lunghezza della nostra stringa che sarà la nostra n, ovvero la lunghezza del vettore soluzione
	size_t length = strlen(r) + 1;

	// Allocazione della memoria
	int* vcurr = malloc((length + 1) * sizeof(int));
	bool* usati = calloc(length + 1, sizeof(bool));

	// Chiamata della funzione di Backtracking (a partire da i = 1)
	RegoleRec(r, length, 0, vcurr, usati);

	free(vcurr);
	free(usati);
}

int main(void) {

	Regole("");
	puts("");
	Regole("I");
	puts("");
	Regole("DI");
	puts("");
	Regole("IIDD");
	puts("");

	return 0;
}