#include "list.h"
#include <string.h>
#include <stdlib.h>

Item* Delete(Item* i, const char* name) {

	Item fake_head = { .next = i };
	Item* prev = ListCreateEmpty();
	Item* succ = ListCreateEmpty();

	while (!ListIsEmpty(i)) {
		if (strcmp(ListGetHeadValue(i)->name, name) == 0) {
			Item* ToBeDeleted = i;				//necessario per la corretta eliminazione
			succ = ListGetTail(i);
			prev->next = succ;
			ElemDelete(&ToBeDeleted->value);	//
			free(ToBeDeleted);					//
			return fake_head.next;
		}
		prev = i;
		i = ListGetTail(i);
	}

	return fake_head.next;
}
/*
int main(void) {

	ElemType ese[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
					{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
					{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
					{"Massimiliano", "Newton", 23, "Modena", "MO", "41126"},
					{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };

	Item* res = ListCreateEmpty();

	for (size_t i = 0; i < sizeof(ese) / sizeof(ElemType); i++) {
		res = ListInsertBack(res, &ese[i]);
	}

	Item* DeleteList = Delete(res, "Elena");
	DeleteList = Delete(res, "Federico");

	return 0;
}
*/

