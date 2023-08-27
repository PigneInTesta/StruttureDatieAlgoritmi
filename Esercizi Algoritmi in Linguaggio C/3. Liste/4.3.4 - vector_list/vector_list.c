#include "list.h"
#include "vector_list.h"

Item* Vector2List(const ElemType* v, size_t v_size, enum ConversionType c) {
	if (v == NULL) {
		return ListCreateEmpty();
	}

	Item* res = NULL;

	if (c == kInOrder) {
		for (size_t i = 0; i < v_size; i++) {
			res = ListInsertBack(res, v + i);
		}
	} else {
		for (size_t j = 0; j < v_size; j++) {
			res = ListInsertHead(v + j, res);
		}
	}

	return res;
}

ElemType* List2Vector(const Item* i, size_t* v_size, enum ConversionType c) {
	if (ListIsEmpty(i)) {
		v_size = 0;
		return NULL;
	}

	ElemType *res = NULL;

	if (c == kInOrder) {
		for (size_t j = 0; !ListIsEmpty(i); j++) {
			res = realloc(res, ++(*v_size) * sizeof(ElemType));
			*(res + j) = ElemCopy(ListGetHeadValue(i));
			i = ListGetTail(i);
		}
	} else {
		const Item* tmp = i;
		while (!ListIsEmpty(i)) {
			res = realloc(res, ++(*v_size) * sizeof(ElemType));
			i = ListGetTail(i);
		}

		for (size_t t = 1; t <= (*v_size); t++) {
			*(res + (*v_size) - t) = ElemCopy(ListGetHeadValue(tmp));
			tmp = ListGetTail(tmp);
		}
	}

	return res;
}