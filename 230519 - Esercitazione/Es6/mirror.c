#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

static bool TreeIsMirrorRec(const Node* t, bool* condizione) {

	Node* l = t;
	Node* r = t;

	if (!TreeIsEmpty(t)) {

		if (ElemCompare(TreeGetRootValue(TreeLeft(l)), TreeGetRootValue(TreeRight(r))) == 0) {
			*condizione = true;
		} else {
			*condizione = false;
		}

		l = TreeGetRootValue(TreeLeft(t));
		r = TreeGetRootValue(TreeRight(t));
	}


	return *condizione;
}

bool TreeIsMirror(const Node* t) {
	if (TreeIsEmpty(t) || TreeIsLeaf(t)) {
		return true;
	}
	bool i = false;
	return TreeIsMirrorRec(t, &i);
}

int main(void) {

	ElemType a[] = { 0, 1, 1, 4, 2, 2, 4 };
	ElemType b[] = { 0, 1, 1, 4, 2, 4, 2 };

	Node* ExampleTree_a = TreeCreateRoot(a + 0, 
							TreeCreateRoot(a + 1, 
								TreeCreateRoot(a + 3, NULL, NULL), 
								TreeCreateRoot(a + 4, NULL, NULL)),
							TreeCreateRoot(a + 2, 
								TreeCreateRoot( a + 5, NULL, NULL), 
								TreeCreateRoot( a + 6, NULL, NULL)));
	Node* ExampleTree_b = TreeCreateRoot(b + 0,
							TreeCreateRoot(b + 1,
								TreeCreateRoot(b + 3, NULL, NULL),
								TreeCreateRoot(b + 4, NULL, NULL)),
							TreeCreateRoot(b + 2,
								TreeCreateRoot(b + 5, NULL, NULL),
								TreeCreateRoot(b + 6, NULL, NULL)));

	bool res = TreeIsMirror(ExampleTree_a);
	res = TreeIsMirror(ExampleTree_b);

	return 0;
}