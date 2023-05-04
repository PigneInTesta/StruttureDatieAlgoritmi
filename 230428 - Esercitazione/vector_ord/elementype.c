#include "elementype.h"
#include <string.h>
//queste funzioni devono variare a seconda del tipo di dato che sto usano


//funzione che fa una deep copy di un intero
ElemType ElemCopy(const ElemType* e) {
	return *e;									
}

//funzione che confronta due interi
int ElemCompare(const ElemType* a, const ElemType* b) {

	if (*a < *b) {							
		return -1;
	} else if (*a > *b) {
		return 1;
	}
	return 0;
}

//funzione che fa lo swap tra interi (uguale a quella per il tipo String)
void ElemSwap(ElemType* a, ElemType* b){
	ElemType tmp = *a;
	*a = *b;
	*b = tmp;
}

//funzione che libera la memoria allocata, ma in questo caso non fa un chezzo perchè non alloco nulla
void ElemDelete(ElemType* e) {}