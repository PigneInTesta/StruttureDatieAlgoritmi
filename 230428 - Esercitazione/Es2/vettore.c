#include "vettore.h"
void VectorInsertionSort(ElemType *Set, ElemType SetSize) {
	for (size_t i = 1; (ElemType) i < SetSize; i++) {
		int temp = Set[i];		//inserisce Set[i] nella sequenza ordinata Set[0...i]
		int j = i;				//definisco la variabile che andrà a scorrere la mia sequenza ordinata
		while (j > 0 && Set[j - 1] > temp) {	
			ElemSwap(Set + j, Set + j - 1);
			j--;
		}
		Set[j] = temp;
	}
}

void VectorSort(Vector* v) {
	if (v != NULL) {
		VectorInsertionSort(v->data, v->size);
	}
}