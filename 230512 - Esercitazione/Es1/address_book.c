#include "list.h"

const ElemType* Find(const Item* i, const char* name) {

	while (!ListIsEmpty(i)) {
		if (strcmp(ListGetHeadValue(i)->name, name) == 0) {
			return ListGetHeadValue(i);
		}
		i = ListGetTail(i);
	}

	return NULL;
}

/*
int main(void) {
	
	ElemType ese[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
					{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
					{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
					{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"}};

	Item* res = ListCreateEmpty();

	for (size_t i = 0; i < sizeof(ese) / sizeof(ElemType); i++) {
		res = ListInsertHead(&ese[i], res);
	}

	const ElemType* NameFind = Find(res, "Elena");
	NameFind = Find(res, "Federico");

	return 0;
}
*/