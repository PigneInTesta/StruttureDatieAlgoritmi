//#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
//#include <stdio.h>
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
Item* Diff(const Item* i1, const Item* i2) {

	Item* res = ListCreateEmpty();

	const Item* tmp_i2 = i2;

	while (!ListIsEmpty(i1)) {
		while (!ListIsEmpty(tmp_i2)) {
			if (ElemCompare(ListGetHeadValue(i1), ListGetHeadValue(tmp_i2)) != 0) {
				tmp_i2 = ListGetTail(tmp_i2);
			}
			else {
				break;
			}
		}

		if (ListIsEmpty(tmp_i2)) {
			res = ListInsertBack(res, ListGetHeadValue(i1));
		}

		tmp_i2 = i2;
		i1 = ListGetTail(i1);
	}

	return res;
}
/*
int main(void) {

	Item* res = Diff(ListLoad("ese1.txt"), ListLoad("ese2.txt"));
	res = Diff(ListLoad("ese1.txt"), ListLoad("vuoto.txt"));
	res = Diff(ListLoad("vuoto.txt"), ListLoad("ese1.txt"));

	return 0;
}
*/