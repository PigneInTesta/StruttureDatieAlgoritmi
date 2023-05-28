#include "list.h"

Item* Sort(Item* i) {

}

int main(void) {

	ElemType ese1[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
						{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
						{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
						{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };

	Item* res1 = ListCreateEmpty();

	for (size_t i = 0; i < sizeof(ese1) / sizeof(ElemType); i++) {
		res1 = ListInsertBack(res1, &ese1[i]);
	}

	Item* NewList = Sort(res1);

	return 0;
}