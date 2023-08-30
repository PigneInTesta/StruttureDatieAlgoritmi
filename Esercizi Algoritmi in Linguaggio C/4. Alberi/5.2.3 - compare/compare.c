#include "tree.h"
#include <stdbool.h>
#include <stdlib.h>

bool TreeAreIdentical(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}

	if (TreeIsEmpty(t1) || TreeIsEmpty(t2)) {
		return false;
	}

	return ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) == 0 && TreeAreIdentical(TreeLeft(t1), TreeLeft(t2)) && TreeAreIdentical(TreeRight(t1), TreeRight(t2));
}

int main(void) {

	ElemType n[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	ElemType d[] = { 12, 4, 21, 0, 5, 18, 77, 2, 8, 9 };

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

	ExampleTree2 = TreeCreateRoot(n + 4,
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

	bool state = TreeAreIdentical(ExampleTree1, ExampleTree2);
	state = TreeAreIdentical(ExampleTree1, ExampleTree3);

	return 0;
}