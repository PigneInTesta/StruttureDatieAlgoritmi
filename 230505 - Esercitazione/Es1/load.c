#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>

Item* ListLoad(const char* filename) {
	
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
/*
int main(void) {
	
	Item* res = ListLoad("data_00.txt");
	res = ListLoad("data_01.txt");
	res = ListLoad("data_02.txt");
	res = ListLoad("vuoto.txt");

	return 0;
}
*/
