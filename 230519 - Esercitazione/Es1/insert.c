#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {
	
	Node *root = n;

	if (TreeIsEmpty(n)) {
		n = TreeCreateRoot(e, NULL, NULL);
		return n;
	}

	while (!TreeIsLeaf(n)) {
		if (ElemCompare(e, TreeGetRootValue(n)) > 0) {
			n = TreeRight(n);
			if (TreeRight(n) == NULL) {
				n->right = TreeCreateRoot(e, NULL, NULL);
				n = TreeRight(n);
				break;
			}
			n = TreeRight(n);
		} else if (ElemCompare(e, TreeGetRootValue(n)) <= 0){
			n = TreeLeft(n);
			if (TreeLeft(n) == NULL) {
				n->left = TreeCreateRoot(e, NULL, NULL);
				n = TreeLeft(n);
				break;
			}
			n = TreeLeft(n);
		}
	}

	return root;
}

Node* BstInsertRec(const ElemType* e, Node* n) {

	if (TreeIsEmpty(n)) {
		n = TreeCreateRoot(e, NULL, NULL);
	} else {
		if (ElemCompare(e, TreeGetRootValue(n)) > 0) {
			n->right = BstInsertRec(e, n->right);
		} else if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
			n->left = BstInsertRec(e, n->left);
		}
	}
	return n;
}

int main(void) {

	ElemType n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8};
	ElemType d[] = { 12, 4, 21, 0, 5, 18, 77, 2, 8, 9};
	
	Node* ExampleTree1 = TreeCreateEmpty();
	Node* ExampleTree2 = TreeCreateEmpty();
	Node* ExampleTree3 = TreeCreateEmpty();

	ExampleTree1 = TreeCreateRoot(n + 4, 
					TreeCreateRoot(n + 3, 
						TreeCreateRoot(n + 1, 
							TreeCreateRoot(n + 1, NULL, NULL), 
							TreeCreateRoot(n + 2, NULL, NULL)), 
						NULL),
					TreeCreateRoot(n + 7, 
						TreeCreateRoot(n + 5, NULL, NULL), 
						TreeCreateRoot(n + 8, NULL, NULL)));

	ExampleTree3 = TreeCreateRoot(d + 0,	//12
					TreeCreateRoot(d + 1,	//4
						TreeCreateRoot(d + 3, NULL, //0
							TreeCreateRoot(d + 7, NULL, NULL)),  //2
						TreeCreateRoot(d + 4, NULL, //5
							TreeCreateRoot(d + 8, NULL, //8
								TreeCreateRoot(d + 9, NULL, NULL)))), //9
					TreeCreateRoot(d + 2, //21
						TreeCreateRoot(d + 5, NULL, NULL), //18
						TreeCreateRoot(d + 6, NULL, NULL))); //77
	ElemType e = 9;
	ElemType b = 6;
	Node* res1 = BstInsertRec(&e, ExampleTree1);
	Node* res2 = BstInsertRec(&e, ExampleTree2);
	//Node* res3 = BstInsert(&b, ExampleTree3);
	Node *res3 = BstInsert(&b, ExampleTree3);

	TreeDelete(res1);
	TreeDelete(res2);
	TreeDelete(res3);

	return 0;
}
