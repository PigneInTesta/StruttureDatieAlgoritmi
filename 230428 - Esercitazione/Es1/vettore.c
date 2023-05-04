#define _CRT_SECURE_NO_WARNINGS
#include "vettore.h"

//implementazione dell'algoritmo QuickSort, per tenere ordinato costantemente il nostro vettore
void QuickSort(ElemType* Set, ElemType first, ElemType last) {
	int i, j, pivot;
	if (first < last) {
		i = first;
		j = last;
		pivot = Set[last];
		do {
			while (Set[i] < pivot) {
				i++;
			}
			while (Set[j] > pivot) {
				j--;
			}
			if (i <= j) {
				ElemSwap(Set + i, Set + j);
				i++;
				j--;
			}
		} while (i <= j);
		QuickSort(Set, first, j);
		QuickSort(Set, i, last);
	}
}

//funzione che aggiunge un elemento al vettore
void VectorPushBack(Vector* v, ElemType e) {							
	if (v->capacity == v->size) {								
		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(int));	
	}															
	v->data[v->size] = e;
	(v->size)++;
}

//funzione che legge da file una sequenza di ElemType e li inserisce in un Vector
Vector* VectorRead(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	//creiamo il nostro vettore, con capacità iniziale pare a 1
	Vector* v = malloc(sizeof(Vector));
	v->capacity = 1;
	v->size = 0;
	v->data = malloc(sizeof(ElemType));
	//andiamo a leggere il file e riempiamo Vector
	while (!feof(f)) {
		ElemType tmp;
		if (ElemRead(f, &tmp) == -1) {	//caso in cui venga passata alla funzione la lista vuota
			v->capacity = 0;
			v->data = realloc(v->data, 0);
			fclose(f);
			return v;
		}
		VectorPushBack(v, tmp);
	}

	fclose(f);
	return v;
}

Vector* VectorReadSorted(const char* filename) {

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}

	Vector* v = malloc(sizeof(Vector));
	v->capacity = 1;
	v->size = 0;
	v->data = malloc(sizeof(ElemType));

	while (!feof(f)) {
		ElemType tmp;
		if (ElemRead(f, &tmp) == -1) {	//caso in cui venga passata alla funzione la lista vuota
			v->capacity = 0;
			v->data = realloc(v->data, 0);
			fclose(f);
			return v;
		}
		VectorPushBack(v, tmp);
		if (v->size > 1) {
			QuickSort(v->data, 0, v->size - 1);
		}
	}

	fclose(f);
	return v;
}