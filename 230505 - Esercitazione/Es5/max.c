//#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
//#include <stdio.h>
#include <stdlib.h>
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
const ElemType* MaxElement(const Item* i) {

	if (ListIsEmpty(i)) {
		return NULL;
	}

	const ElemType* max = ListGetHeadValue(i);
	
	while (!ListIsEmpty(i)) {
		if (ElemCompare(max, ListGetHeadValue(i)) == -1) {
			max = ListGetHeadValue(i);
		}
		i = ListGetTail(i);
	} 

	return max;
}

/*
int main(void) {

	const ElemType* res = MaxElement(ListLoad("ese1.txt"));
	res = MaxElement(ListLoad("ese2.txt"));
	res = MaxElement(ListLoad("vuoto.txt"));

	return 0;
}
*/