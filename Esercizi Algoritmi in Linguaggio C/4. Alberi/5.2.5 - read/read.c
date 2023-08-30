#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

Node* TreeReadRec(FILE *f) {
	ElemType c;
	if (fscanf(f, " %c", &c) != 1) {			//lo spazio davanti al formato della stringa, scarta tutti gli spazi (isspace, quindi anche tabulazioni, ...)
		return TreeCreateEmpty();
	}

	if (c == '.') {
		fscanf(f, " %c", &c);
		return TreeCreateRoot(&c, NULL, NULL);
	}

	Node* l = TreeReadRec(f);
	Node* r = TreeReadRec(f);

	return TreeCreateRoot(&c, l, r);
}

Node* TreeRead(const char* filename) {
	FILE* f = fopen(filename, "rt");
	if (!f || feof(f)) {
		return TreeCreateEmpty();
	}

	Node* res = TreeReadRec(f);
	fclose(f);

	return res;
}

int main(void) {

	Node* res = TreeRead("albero_01.txt");
	TreeDelete(res);

	res = TreeRead("albero_02.txt");
	TreeDelete(res);

	res = TreeRead("albero_03.txt");
	TreeDelete(res);

	res = TreeRead("albero_04.txt");
	TreeDelete(res);

	res = TreeRead("albero_05.txt");
	TreeDelete(res);

	res = TreeRead("albero_06.txt");
	TreeDelete(res);

	res = TreeRead("albero_07.txt");
	TreeDelete(res);

	res = TreeRead("albero_08.txt");
	TreeDelete(res);

	return 0;
}