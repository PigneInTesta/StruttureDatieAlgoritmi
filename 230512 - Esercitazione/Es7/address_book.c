#include "list.h"

// Funzione per il calcolo della lunghezza di una lista
int ListLength(const Item* i) {
	int j = 0;
	while (!ListIsEmpty(i)) {
		j++;
		i = ListGetTail(i);
	}
	return j;
}

Item* AppendMod(Item* i1, Item* i2) {

	if (ListIsEmpty(i1) && ListIsEmpty(i2)) {
		return i1;
	} else if (ListIsEmpty(i2)) {
		return i1;
	} else if (ListIsEmpty(i1)) {
		return i2;
	}

	Item fake_head_i1 = { .next = i1 };
	Item fake_head_i2 = { .next = i2 };
	int dim = ListLength(i1);
	Item* prev = ListCreateEmpty();

	for (int i = 0; i < dim - 1; i++) {
		i1 = ListGetTail(i1);
	}
	prev = i1;
	prev->next = fake_head_i2.next;

	return fake_head_i1.next;
}
/*
int main(void) {

	ElemType ese1[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
					{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
					{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
					{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };

	ElemType ese2[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
					{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
					{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
					{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };

	Item* res1 = ListCreateEmpty();
	Item* res2 = ListCreateEmpty();

	for (size_t i = 0; i < sizeof(ese1) / sizeof(ElemType); i++) {
		res1 = ListInsertBack(res1, &ese1[i]);
		res2 = ListInsertBack(res2, &ese2[i]);
	}

	Item* NewList = AppendMod(res1, res2);
	NewList = AppendMod(NULL, res2);

	return 0;
}
*/