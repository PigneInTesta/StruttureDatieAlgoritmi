#include "tree.h"

static Node* TreeBinInsOrd(const ElemType* b, Node* bst) {
	if (TreeIsEmpty(bst)) {
		return TreeCreateRoot(b, TreeCreateEmpty(), TreeCreateEmpty());
	}

	Node* root = bst;

	while (1) {
		if (ElemCompare(TreeGetRootValue(bst), b) > 0 && TreeLeft(bst) == NULL) {
			bst->left = TreeCreateRoot(b, TreeCreateEmpty(), TreeCreateEmpty());
			break;
		} else if (ElemCompare(TreeGetRootValue(bst), b) > 0 && TreeLeft(bst) != NULL) {
			bst = bst->left;
		} else if (ElemCompare(TreeGetRootValue(bst), b) <= 0 && TreeRight(bst) == NULL) {
			bst->right = TreeCreateRoot(b, TreeCreateEmpty(), TreeCreateEmpty());
			break;
		} else if (ElemCompare(TreeGetRootValue(bst), b) <= 0 && TreeRight(bst) != NULL) {
			bst = bst->right;
		}
	}

	return root;
}

static void Tree2BstRec(const Node* t, Node** bst) {

	if (TreeIsEmpty(t)) {
		return;
	}

	Tree2BstRec(TreeLeft(t), bst);

	(*bst) = TreeBinInsOrd(TreeGetRootValue(t), *bst);

	Tree2BstRec(TreeRight(t), bst);
}

Node* Tree2Bst(const Node* t) {
	if (TreeIsEmpty(t)) {
		return TreeCreateEmpty();
	}

	Node* bst = TreeCreateEmpty();
	Tree2BstRec(t, &bst);
	return bst;
}

int main(void) {

	ElemType a[] = { 6, 2, 9, 3, 8, 3, 5 };

	Node* ExampleTreeA = TreeCreateEmpty();

	ExampleTreeA = TreeCreateRoot(a + 0,
		TreeCreateRoot(a + 1,
			TreeCreateRoot(a + 3, NULL, NULL),
			TreeCreateRoot(a + 4, NULL,
				TreeCreateRoot(a + 6, NULL, NULL))),
		TreeCreateRoot(a + 2, NULL,
			TreeCreateRoot(a + 5, NULL, NULL)));

	Node* res = Tree2Bst(ExampleTreeA);

	TreeDelete(ExampleTreeA);
	TreeDelete(res);

	return 0;
}