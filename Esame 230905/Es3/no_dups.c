#include "no_dups.h"

static bool IsInVett(ElemType* vet, const ElemType* element, size_t dim_vett) {
	for (int j = 0; j < (int)dim_vett; j++) {
		if (ElemCompare(vet + j, element) == 0) {
			return true;
		}
	}

	return false;
}

Item* RemoveDuplicates(const Item* i) {
	if (ListIsEmpty(i)) {
		return ListCreateEmpty();
	}

	Item* res = ListCreateEmpty();

	size_t dim_v = 1;
	ElemType* v = malloc(sizeof(ElemType));

	for (int j = 0; !ListIsEmpty(i);) {
		if (!IsInVett(v, ListGetHeadValue(i), dim_v)) {
			res = ListInsertBack(res, ListGetHeadValue(i));
			v[j] = ElemCopy(ListGetHeadValue(i));
			i = ListGetTail(i);
			dim_v++;
			j++;
			v = realloc(v, dim_v * sizeof(ElemType));
		} else {
			i = ListGetTail(i);
		}
	}

	free(v);
	return res;
}