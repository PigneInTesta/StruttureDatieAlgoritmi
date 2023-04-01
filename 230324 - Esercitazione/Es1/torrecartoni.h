#ifndef TORRE_CARTONI_H
#define TORRE_CARTONI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    unsigned p; // Peso
    unsigned a; // Altezza
    unsigned l; // Limite
} Cartone;

extern void TorreCartoni(const Cartone* c, size_t n);

#endif /* TORRE_CARTONI_H */