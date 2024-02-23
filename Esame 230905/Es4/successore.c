#include "tree.h"


const Node* Successore(const Node* t, const Node* n) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}

	if (ElemCompare(TreeGetRootValue(t), TreeGetRootValue(n)) > 0) {
		return t;
	}

	return Successore(TreeLeft(t), n);
	return Successore(TreeRight(t), n);
}

//int main(void) {
//
//	ElemType d[] = { 3, 2, 1, 5 };
//	Node* Tree_D = TreeCreateEmpty();
//
//	Tree_D = TreeCreateRoot(d + 0,
//		TreeCreateRoot(d + 1,
//			TreeCreateRoot(d + 3, NULL, NULL), NULL),
//		TreeCreateRoot(d + 2, NULL, NULL));
//
//	const Node* res = Successore(Tree_D, Tree_D);
//
//	TreeDelete(Tree_D);
//
//	return 0;
//}