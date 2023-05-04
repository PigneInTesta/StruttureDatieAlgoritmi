#ifndef ELEMENTYPE_H_
#define ELEMETYPE_H_

#include <stdlib.h>
#include <stdint.h>


typedef int ElemType;

ElemType ElemCopy(const ElemType* e);
int ElemCompare(const ElemType* a, const ElemType* b);
void ElemSwap(ElemType* a, ElemType* b);
void ElemDelete(ElemType* e);

#endif // !ELEMENTYPE_H_
