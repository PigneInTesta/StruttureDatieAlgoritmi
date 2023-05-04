//Rendiamo le funzioni indipendenti rispetto al tipo, una volta capite c'è le forniranno loro all'esame

//Iniziamo con un vettore

#include <stdlib.h>
#include <stdint.h>

typedef struct {
	size_t capacity;		//quanta memoria abbiamo effettivamente allocato per il nostro vettore
	size_t size;			//numeri di elementi che sono presenti nel vettore
	int* dati;				//dati che sono presenti nel nostro vettore
} Vector;

/*
//funzione che inserisce un elemento al nostro vettore
void VectorPushBack(Vector *v, int e){							//Vector v deve essere passato come un puntatore perchè altrimenti capacity e size non sarebbeto passati al di fuori della funzione
	if (v->capacity == v->size) {								//ovvero in memoria non c'è più posto
		v->capacity *= 2;
		v->dati = realloc(v->dati, v->capacity * sizeof(int));	//non è una buona scelta aumentare il vettore solo di un elemento (tramite realloc) perchè
	}															//nel peggior dei casi non c'è posto in memoria per aggiungere quella che ci servirebbe
	v->dati[v->size] = e;
	(v->size)++;
}
*/

//funzione classica che fa lo swap, ci servirà anche dopo
void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
//funzione che ordina il vettore
void SelectionSort(Vector *v) {
	for (size_t i = 0; i < v->size; ++i) {
		size_t minpos = i;
		for (size_t j = i + 1; j < v->size; ++j) {
			if (v->dati[j] < v->dati[minpos]) {					//l'unico non è obbligatorio ma farei uno scambio inutile e non preserverei
				minpos = j;										//l'ordine dei valori
			}
		}
		if (i != minpos) {
			//Swap(&v->dati[i], &v->dati[minpos]);
			Swap(v->dati + i, v->dati + minpos);
		}
	}
}
*/
/*
int main(void) {

	Vector v = { .capacity = 1, .size = 0, .dati = malloc(sizeof(int)) };

	srand(0);							//riempiamo il nostro vettore con numeri pseudo-casuali con la funz. srand
	for (int i = 0; i < 20; ++i) {
		VectorPushBack(&v, rand());
	}

	SelectionSort(&v);

	free(v.dati);

	return EXIT_SUCCESS;
}
*/