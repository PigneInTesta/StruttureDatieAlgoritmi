//Rendiamo le funzioni indipendenti rispetto al tipo, una volta capite c'è le forniranno loro all'esame

//Passiamo alle stringhe

#include "elementype_string.h"

typedef struct {
	size_t capacity;		//quanta memoria abbiamo effettivamente allocato per il nostro vettore
	size_t size;			//numeri di elementi che sono presenti nel vettore
	ElemType* dati;			//dati che sono effettivamente presente nel nostro vettore
} Vector;


//funzione che inserisce un elemento al nostro vettore, non gestisce la nostra stringa
void VectorPushBack(Vector* v, const ElemType *e) {					//la stringa non conviene passarla per copia perchè il costo sarebbe maggiore
	if (v->capacity == v->size) {									
		v->capacity *= 2;
		v->dati = realloc(v->dati, v->capacity * sizeof(ElemType));
	}																
	v->dati[v->size] = ElemCopy(e);								//sto copiando il contenuto della struct String (size e dati), shallow copy ma
	(v->size)++;													//ma noi vogliamo una deep copy (ovvero che tutti i dati vengano copiati)
}


void SelectionSort(Vector* v) {
	for (size_t i = 0; i < v->size; ++i) {
		size_t minpos = i;
		for (size_t j = i + 1; j < v->size; ++j) {
			if (ElemCompare(v->dati + j, v->dati + minpos) < 0) {			//meglio non mettere l'uguale
				minpos = j;				
			}
		}
		if (i != minpos) {
			//Swap(&v->dati[i], &v->dati[minpos]);
			ElemSwap(v->dati + i, v->dati + minpos);
		}
	}
}

int main(void) {

	
	Vector v = { .capacity = 1, .size = 0, .dati = malloc(sizeof(ElemType)) };

	ElemType s[] = {{.dati = "pippo", .size = 5},
					{.dati = "pluto", .size = 5},
					{.dati = "paperino", .size = 8} };

	for (int i = 0; i < 3; ++i) {
		VectorPushBack(&v, s + i);
	}

	SelectionSort(&v);

	for (int i = 0; i < (int) v.size; ++i) {
		ElemDelete(v.dati + i);
	}
		
	free(v.dati);

	return EXIT_SUCCESS;
}