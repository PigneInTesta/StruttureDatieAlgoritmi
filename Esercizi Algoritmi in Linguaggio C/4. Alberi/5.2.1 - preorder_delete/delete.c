#define _CRTDBG_MAP_ALLOC
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

void TreePreOrderDelete(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}

	Node* l = TreeLeft(t);
	Node* r = TreeRight(t);
	printf("%d ", *TreeGetRootValue(t));
	ElemDelete(TreeGetRootValue(t));
	free(t);
	
	TreePreOrderDelete(l);
	TreePreOrderDelete(r);
}

int main(void) {

	ElemType n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	ElemType d[] = { 12, 4, 21, 0, 5, 18, 77, 2, 8, 9 };

	Node* ExampleTree1 = TreeCreateEmpty();
	Node* ExampleTree2 = TreeCreateEmpty();
	Node* ExampleTree3 = TreeCreateEmpty();
	//BST
	ExampleTree1 = TreeCreateRoot(n + 4,
		TreeCreateRoot(n + 3,
			TreeCreateRoot(n + 1,
				TreeCreateRoot(n + 1, NULL, NULL),
				TreeCreateRoot(n + 2, NULL, NULL)),
			NULL),
		TreeCreateRoot(n + 7,
			TreeCreateRoot(n + 5, NULL, NULL),
			TreeCreateRoot(n + 8, NULL, NULL)));

	//BST
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

	TreePreOrderDelete(ExampleTree1);
	puts("");
	TreePreOrderDelete(ExampleTree2);
	puts("");
	TreePreOrderDelete(ExampleTree3);
	puts("");

	_CrtDumpMemoryLeaks();	//Stampa del rapporto sulla memoria (memory dump)

	return 0;
}