#include "list.h"

Item* Append(const Item* i1, const Item* i2) {

	Item* NewList = ListCreateEmpty();

	while (!ListIsEmpty(i1)) {
		NewList = ListInsertBack(NewList, ListGetHeadValue(i1));
		i1 = ListGetTail(i1);
	}
	while (!ListIsEmpty(i2)) {
		NewList = ListInsertBack(NewList, ListGetHeadValue(i2));
		i2 = ListGetTail(i2);
	}

	return NewList;
}
/*
int main(void) {

	ElemType ese[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
					{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
					{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
					{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };

	Item* res = ListCreateEmpty();

	for (size_t i = 0; i < sizeof(ese) / sizeof(ElemType); i++) {
		res = ListInsertBack(res, &ese[i]);
	}

	Item* NewList = Append(res, res);
	NewList = Append(NULL, NULL);

	return 0;
}
*/