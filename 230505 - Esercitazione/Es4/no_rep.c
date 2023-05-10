//#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
//#include <stdio.h>
#include <stdbool.h>

//funzione che verifica se l'elemento che voglio aggiungere al mio vettore risultante, è già presente
static bool IsInRes(const Item* res, const ElemType* number) {
	while (!ListIsEmpty(res)) {
		if (ElemCompare(ListGetHeadValue(res), number) == 0) {
			return true;
		}
		res = ListGetTail(res);
	}
	return false;
}
/*
static Item* ListLoad(const char* filename) {

	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return ListCreateEmpty();
	}

	Item* res = ListCreateEmpty();

	while (!feof(f)) {
		ElemType tmp;
		if (ElemRead(f, &tmp) != -1) {
			res = ListInsertHead(&tmp, res);
		} else {
			fclose(f);
			return res;
		}
	}

	fclose(f);
	return res;

}
*/
Item* IntersectNoRep(const Item* i1, const Item* i2) {

	Item* res = ListCreateEmpty();

	const Item* tmp_i2 = i2;

	while (!ListIsEmpty(i1)) {
		while (!ListIsEmpty(tmp_i2)) {
			if (ElemCompare(ListGetHeadValue(i1), ListGetHeadValue(tmp_i2)) == 0 && !IsInRes(res, ListGetHeadValue(tmp_i2))) {
				res = ListInsertBack(res, ListGetHeadValue(i1));
				break;
			}
			tmp_i2 = ListGetTail(tmp_i2);
		}
		tmp_i2 = i2;
		i1 = ListGetTail(i1);
	}

	return res;
}

Item* DiffNoRep(const Item* i1, const Item* i2) {

	Item* res = ListCreateEmpty();

	const Item* tmp_i2 = i2;

	while (!ListIsEmpty(i1)) {
		while (!ListIsEmpty(tmp_i2)) {
			if (ElemCompare(ListGetHeadValue(i1), ListGetHeadValue(tmp_i2)) != 0) {
				tmp_i2 = ListGetTail(tmp_i2);
			} else {
				break;
			}
		}

		if (ListIsEmpty(tmp_i2) && !IsInRes(res, ListGetHeadValue(i1))) {
			res = ListInsertBack(res, ListGetHeadValue(i1));
		}

		tmp_i2 = i2;
		i1 = ListGetTail(i1);
	}

	return res;
}
/*
int main(void) {

	Item* res = IntersectNoRep(ListLoad("ese1.txt"), ListLoad("ese2.txt"));
	res = DiffNoRep(ListLoad("ese1.txt"), ListLoad("ese2.txt"));

	return 0;
}
*/
