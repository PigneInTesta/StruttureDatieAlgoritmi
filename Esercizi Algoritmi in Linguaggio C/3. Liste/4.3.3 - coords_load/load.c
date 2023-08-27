#define _CRT_SECURE_NO_WARNINGS
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

Item* ListLoad(const char* filename) {
	FILE* f = fopen(filename, "rt");
	if (!f || feof(f)) {
		return ListCreateEmpty();
	}

	Item* res = ListCreateEmpty();
	ElemType tmp;

	while (!feof(f)) {
		if (ElemRead(f, &tmp) > 0) {
			res = ListInsertHead(&tmp, res);
		}
	}

	fclose(f);
	return res;
}

int main(void) {

	Item* res_A = ListLoad("coords_01.txt");
	Item* res_B = ListLoad("coords_02.txt");
	Item* res_C = ListLoad("coords_03.txt");
	Item* res_D = ListLoad("coords_04.txt");

	ListDelete(res_A);
	ListDelete(res_B);
	ListDelete(res_C);
	ListDelete(res_D);

	return 0;
}