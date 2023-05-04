#include "vettore.h"

int VectorFind(const Vector* v, const ElemType* e) {
	if (v != NULL) {
		for (size_t i = 0; i < v->size; i++) {
			if (v->data[i] == *e) {
				return i;
			}
		}

		return -1;
	}
	return -1;
}