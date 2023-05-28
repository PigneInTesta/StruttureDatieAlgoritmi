#include "list.h"
#include <string.h>

Item* Filtra(const Item* i, const char* city) {
	
	Item* filtered_city = ListCreateEmpty();

	while (!ListIsEmpty(i)) {
		if (strcmp(ListGetHeadValue(i)->city, city) == 0) {
			filtered_city = ListInsertBack(filtered_city, ListGetHeadValue(i));
		}
		i = ListGetTail(i);
	}

	return filtered_city;
}
/*
int main(void) {

	ElemType ese[] = { {"Michele", "Firenze", 12, "Modena", "MO", "41126"},
					{"Federico", "Peschiera", 54, "Modena", "MO", "41126"},
					{"Massimiliano", "Roma", 23, "Firenze", "FI", "50100"},
					{"Stefano", "Ciro Menotti", 10, "Milano", "MI", "20019"} };

	Item* res = ListCreateEmpty();

	for (size_t i = 0; i < sizeof(ese) / sizeof(ElemType); i++) {
		res = ListInsertHead(&ese[i], res);
	}

	Item* FilteredCity = Filtra(res, "Modena");
	FilteredCity = Filtra(res, "Lama dei Peligni");

	return 0;
}
*/