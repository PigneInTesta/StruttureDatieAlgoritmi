#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

static bool TreeIsMirrorRec(Node *l, Node *r) {
	// Caso base 1: gli alberi sono entrambi vuoti
	if (TreeIsEmpty(l) && TreeIsEmpty(r)) {
		return true;
	}

	// Caso base 1: solo uno dei due alberi è vuoto
	if (TreeIsEmpty(l) || TreeIsEmpty(r)) {
		return false;
	}

	return ElemCompare(TreeGetRootValue(l), TreeGetRootValue(r)) == 0 && TreeIsMirrorRec(TreeLeft(l), TreeRight(r)) && TreeIsMirrorRec(TreeRight(l), TreeLeft(r));

}

bool TreeIsMirror(Node* t) {
	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
}

//int main(void) {
//
//	ElemType c[] = { 0, 1, 4, 2 };
//
//	Node* ExampleTree1 = TreeCreateEmpty();		//mirrored
//	Node* ExampleTree2 = TreeCreateEmpty();		//not mirrored
//	Node* ExampleTree3 = TreeCreateEmpty();
//	Node* ExampleTree4 = TreeCreateEmpty();
//
//	ExampleTree1 = TreeCreateRoot(c + 0,
//		TreeCreateRoot(c + 1,
//			TreeCreateRoot(c + 2, NULL, NULL),
//			TreeCreateRoot(c + 3, NULL, NULL)),
//		TreeCreateRoot(c + 1,
//			TreeCreateRoot(c + 3, NULL, NULL),
//			TreeCreateRoot(c + 2, NULL, NULL)));
//
//	ExampleTree2 = TreeCreateRoot(c + 0,
//		TreeCreateRoot(c + 1,
//			TreeCreateRoot(c + 2, NULL, NULL),
//			TreeCreateRoot(c + 3, NULL, NULL)),
//		TreeCreateRoot(c + 1,
//			TreeCreateRoot(c + 2, NULL, NULL),
//			TreeCreateRoot(c + 3, NULL, NULL)));
//
//	ExampleTree4 = TreeCreateRoot(c + 0, NULL, NULL);
//
//	bool state = TreeIsMirror(ExampleTree1);
//	state = TreeIsMirror(ExampleTree2);
//	state = TreeIsMirror(ExampleTree3);
//	state = TreeIsMirror(ExampleTree4);
//
//	TreeDelete(ExampleTree1);
//	TreeDelete(ExampleTree2);
//	TreeDelete(ExampleTree3);
//	TreeDelete(ExampleTree4);
//
//	return 0;
//}