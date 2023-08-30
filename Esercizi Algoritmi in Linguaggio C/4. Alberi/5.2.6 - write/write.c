#define _CRT_SECURE_NO_WARNINGS
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Node* TreeReadRec(FILE* f) {
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

void TreeWriteRec(const Node* t, FILE *f, int p) {
	if (TreeIsEmpty(t)) {
		return;
	}

	if (TreeIsLeaf(t)) {
		for (int i = 0; i < 4 * p; fputc(' ', f), i++);
		fprintf(f, ".%c\n", *TreeGetRootValue(t));
		return;
	}

	fprintf(f, "%*c\n", 4 * p + 1, *TreeGetRootValue(t));
	TreeWriteRec(TreeLeft(t), f, p + 1);
	TreeWriteRec(TreeRight(t), f, p + 1);
}

bool TreeWrite(const Node* t, const char* filename) {
	FILE* f = fopen(filename, "wt");
	
	if (!f) {
		return false;
	}

	TreeWriteRec(t, f, 0);

	fclose(f);

	return true;
}

int main(void) {

	Node* res = TreeRead("albero_01.txt");
	bool state = TreeWrite(res, "out1.txt");
	TreeDelete(res);
	
	res = TreeRead("albero_02.txt");
	state = TreeWrite(res, "out2.txt");
	TreeDelete(res);
	
	res = TreeRead("albero_03.txt");
	state = TreeWrite(res, "out3.txt");
	TreeDelete(res);

	state = TreeWrite(TreeCreateEmpty(), "out4.txt");

	return 0;
}