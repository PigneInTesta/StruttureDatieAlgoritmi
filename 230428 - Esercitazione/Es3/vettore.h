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

int VectorFind(const Vector* v, const ElemType* e);

#endif // !VETTORE_H_
