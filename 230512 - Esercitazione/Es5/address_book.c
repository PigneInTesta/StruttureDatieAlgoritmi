#include "list.h"

Item* Reverse(const Item* i) {
	
	Item* ReverseList = ListCreateEmpty();

	while (!ListIsEmpty(i)) {
		ReverseList = ListInsertHead(ListGetHeadValue(i), ReverseList);
		i = ListGetTail(i);
	}

	return ReverseList;
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

	Item* ReverseList = Reverse(res);
	ReverseList = Reverse(NULL);

	return 0;
}
*/