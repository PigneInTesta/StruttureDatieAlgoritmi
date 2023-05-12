#define _CRT_SECURE_NO_WARNINGS
#include "gioielli.h"

//funzione che ordina la nostra struttura dati GioielloApp secondo l'appetibilità in modo decrescente
void JewelsInsertionSort(GioielloApp A[], int dim){
	for (int i = 1; i < dim; i++) {
		GioielloApp temp = A[i];
		int j = i;
		while (j > 0 && A[j - 1].appetibilita < temp.appetibilita) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = temp;
	}
}

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	
	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return NULL;
	}

	int flag_a = 0, flag_b = 0;

	//Contiamo quanti gioielli ci sono nel file (n. di righe)
	while (!feof(f)) {
		int num_gioielli = fgetc(f);
		if (num_gioielli == '\n' || num_gioielli == EOF) {
			flag_a++;
		}
	}

	rewind(f);

	Gioiello* Jewels = malloc(flag_a * sizeof(Gioiello));
	Gioiello* res = malloc(flag_a * sizeof(Gioiello));
	GioielloApp* JewelsApp = malloc(flag_a * sizeof(GioielloApp));
	
	//Assegniamo i dati dal file alla struttura dati
	for (int i = 0; i < flag_a; i++) {
		fscanf(f, "%d %f %f", &Jewels[i].codice, &Jewels[i].peso, &Jewels[i].prezzo);
		JewelsApp[i].codice = Jewels[i].codice;
		JewelsApp[i].peso = Jewels[i].peso;
		JewelsApp[i].prezzo = Jewels[i].prezzo;
		JewelsApp[i].appetibilita = Jewels[i].peso / Jewels[i].prezzo;
	}

	//Ordiniamo la nostra struttura dati
	JewelsInsertionSort(JewelsApp, flag_a);

	//Assegniamo la struttura dati ordinata alla struttura dati di ritorno
	for (int k = 0; k < flag_a; k++) {
		Jewels[k].codice = JewelsApp[k].codice;
		Jewels[k].prezzo = JewelsApp[k].prezzo;
		Jewels[k].peso = JewelsApp[k].peso;
	}

	//Cerchiamo una soluzione effettiva al problema
	//Il problema è qui, sistemare j quando un gioiello sfora il budget
	for (int j = 0; j < flag_a && budget != 0; j++) {
		if (budget >= Jewels[j].prezzo) {
			res[flag_b] = Jewels[j];
			budget -= res[flag_b].prezzo;
			flag_b++;
		}
	}

	(*ret_size) = flag_b;
	res = realloc(res, flag_b * sizeof(Gioiello));
	free(Jewels);
	free(JewelsApp);
	fclose(f);
	return res;
}