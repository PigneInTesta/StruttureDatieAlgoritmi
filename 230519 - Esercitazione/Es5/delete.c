#include "tree.h"

Node* DeleteBstNode(Node* n, const ElemType* key) {

	Node* root = n;
	Node* pl = TreeCreateEmpty();
	Node* pr = TreeCreateEmpty();

	while (ElemCompare(TreeGetRootValue(n), key) != 0 && !TreeIsEmpty(n)) {
		if (ElemCompare(key, TreeGetRootValue(n)) < 0) {
			pl = n;
			//Node* pr = TreeCreateEmpty();
			n = TreeLeft(n);
		} else {
			//Node* pl = TreeCreateEmpty();
			pr = n;
			n = TreeRight(n);
		}
	}

	//1° Caso: il nodo da eliminare è una foglia
	if (TreeIsEmpty(TreeLeft(n)) && TreeIsEmpty(TreeRight(n))) {
		if (!TreeIsEmpty(pl)) {
			ElemDelete(&n->value);
			pl->left = NULL;
		}
		ElemDelete(&n->value);
		pr->right = NULL;
	}

	Node* next = TreeCreateEmpty();

	//2° Caso: il nodo da eliminare ha un solo figlio
	if (TreeIsEmpty(TreeLeft(n)) && !TreeIsEmpty(TreeRight(n))) {
		next = TreeRight(n);
	} else {
		if (!TreeIsEmpty(TreeLeft(n)) && TreeIsEmpty(TreeRight(n))) {
			next = TreeLeft(n);
		}
	}
	if (!TreeIsEmpty(pl) && !TreeIsEmpty(next)) {
		ElemDelete(&n->value);
		pl->left = next;
	} else if (TreeIsEmpty(pl) && !TreeIsEmpty(next)){
		ElemDelete(&n->value);
		pr->right = next;
	}

	//SISTEMARE
	//3° Caso: il nodo da eliminare ha due figli
	if (!TreeIsEmpty(TreeLeft(n)) && !TreeIsEmpty(TreeRight(n))) {
		if (!TreeIsEmpty(pl)) {
			next = n;
			while (!TreeIsEmpty(next) && !TreeIsEmpty(TreeLeft(next))) {
				if (ElemCompare(TreeGetRootValue(next), TreeGetRootValue(TreeLeft(next))) > 0) {
					next = TreeRight(next);
				} else {
					next = TreeLeft(next);
				}
			}
		} else {
			next = pr;
			while (!TreeIsEmpty(next) && !TreeIsEmpty(TreeLeft(next))) {
				if (ElemCompare(TreeGetRootValue(next), TreeGetRootValue(TreeLeft(next))) > 0) {
					next = TreeRight(next);
				} else {
					next = TreeLeft(next);
				}
			}
		}
		ElemSwap(TreeGetRootValue(n), TreeGetRootValue(next));
		ElemDelete(&next->value);
		next = NULL;
	}

	return root;
}

int main(void) {

	ElemType a[] = { 5, 4, 7, 3, 8, 6, 9, 1, 8, 10 };
	Node* TreeA = TreeCreateRoot(a + 0, 
					TreeCreateRoot(a + 1, 
						TreeCreateRoot(a + 3, 
							TreeCreateRoot(a + 7, NULL, NULL), NULL),
						TreeCreateRoot(a + 4, NULL, NULL)), 
					TreeCreateRoot(a + 2, 
						TreeCreateRoot(a + 5, NULL, NULL), 
						TreeCreateRoot(a + 6, 
							TreeCreateRoot(a + 8, NULL, NULL), 
							TreeCreateRoot(a + 9, NULL, NULL))));

	Node* res = TreeCreateEmpty();
	ElemType keys[] = { 4, 10, 3 };
	res = DeleteBstNode(TreeA, keys + 1); //foglia
	res = DeleteBstNode(TreeA, keys + 2); //ha un solo figlio
	res = DeleteBstNode(TreeA, keys + 0); //due figli
	
	return 0;
}