#ifndef GIOIELLI_H_
#define GIOIELLI_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;

//struttura dati che consente di tenere conto dei valori di appetibilita
typedef struct {
	int codice;
	float peso;
	float prezzo;
	float appetibilita;
} GioielloApp;

extern Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);

#endif /* GIOIELLI_H_ */