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

Item* Intersect(const Item* i1, const Item* i2) {

	Item* res = ListCreateEmpty();

	//if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
	//	return res;
	//}

	const Item* tmp_i2 = i2;

	while (!ListIsEmpty(i1)) {
		while (!ListIsEmpty(tmp_i2)) {
			if (*(ListGetHeadValue(i1)) == *(ListGetHeadValue(tmp_i2))) {
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
/*
int main(void) {

	Item* res = Intersect(ListLoad("vuoto.txt"), ListLoad("ese2.txt"));

	return 0;
}
*/
