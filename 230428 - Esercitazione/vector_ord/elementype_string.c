#include "elementype.h"
#include <string.h>

//funzione che fa una deep copy di una stringa
ElemType ElemCopy(const ElemType* e) {
	ElemType copy = { .size = e->size, .dati = malloc(sizeof(char) * e->size) };
	memcpy(copy.dati, e->dati, sizeof(char) * e->size);
	return copy;
}

//funzione che confronta due stringhe
int ElemCompare(const ElemType* a, const ElemType* b) {
	for (size_t i = 0; i < a->size && i < b->size; ++i) {
		if (a->dati[i] < b->dati[i]) {
			return -1;
		} else if (a->dati[i] > b->dati[i]) {
			return 1;
		}
	}

	if (a->size < b->size) {								//non hanno la stessa lunghezza
		return -1;
	} else if (a->size > b->size) {
		return 1;
	}

	return 0;
}

//funzione che fa lo swap tra stringhe
void ElemSwap(ElemType* a, ElemType* b){
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

//funzione che libera la memoria allocata
void ElemDelete(ElemType* e) {
	free(e->dati);
}