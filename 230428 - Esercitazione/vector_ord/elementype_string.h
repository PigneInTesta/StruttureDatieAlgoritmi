#ifndef ELEMENTYPE_H_
#define ELEMETYPE_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct {
	size_t size;			//non dobbiamo includere il terminatore perchè non sono lo standard per le stringhe in C
	char* dati;
} String;

typedef String ElemType;

ElemType ElemCopy(const ElemType* e);
int ElemCompare(const ElemType* a, const ElemType* b);
void ElemSwap(ElemType* a, ElemType* b);
void ElemDelete(ElemType* e);

#endif // !ELEMENTYPE_H_
