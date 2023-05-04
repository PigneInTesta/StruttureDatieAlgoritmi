#ifndef VETTORE_H_
#define VETTORE_H_

#include "elemtype.h"
#include <stdlib.h>

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

typedef int ElemType;

void VectorSort(Vector* v);

#endif // !VETTORE_H_
