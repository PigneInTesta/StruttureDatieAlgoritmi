#ifndef VETTORE_H_
#define VETTORE_H_

#include <stdlib.h>
#include <stdio.h>
#include "elemtype.h"

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

typedef int ElemType;

Vector* VectorRead(const char* filename);
Vector* VectorReadSorted(const char* filename);

#endif // !VETTORE_H_
