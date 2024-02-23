#include "tree.h"
#include <stdlib.h>

static int FindMaxPos(const ElemType *v, size_t first, size_t last) {
	int max = 0;
	for (size_t i = first; i <= last; i++) {
		if (v[max] < v[i]) {
			max = (int) i;
		}
	}

	return max;
}

Node* CreateMaxBinTreeRec(const ElemType* v, size_t first, size_t last) {
	
	if (FindMaxPos(v, first, last) == 0 || FindMaxPos(v, first, last) == last) {
		return TreeCreateRoot(v + FindMaxPos(v, first, last), l, r);
	}

	Node* l = CreateMaxBinTreeRec(v, first, FindMaxPos(v, first, last) - 1);
	Node* r = CreateMaxBinTreeRec(v, FindMaxPos(v, first, last) + 1, last);

	
}

Node* CreateMaxBinTree(const ElemType* v, size_t v_size) {
	return CreateMaxBinTreeRec(v, 0, v_size);
}

int main(void) {
	{
		ElemType v[] = { 3, 2, 1, 6, 0, 5 };
		size_t dim = sizeof(v) / sizeof(ElemType);
		Node* res = CreateMaxBinTree(v, dim);

		TreeDelete(res);
	}

	{
		ElemType v[] = { 3, 2, 1};
		size_t dim = sizeof(v) / sizeof(ElemType);
		Node* res = CreateMaxBinTree(v, dim);

		TreeDelete(res);
	}
}