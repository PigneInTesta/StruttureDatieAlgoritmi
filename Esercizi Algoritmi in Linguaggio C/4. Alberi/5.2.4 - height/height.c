#include "tree.h"

void TreeHeightRec(const Node* t, int *h_max, int h_curr) {
	if (TreeIsLeaf(t)) {
		if (h_curr > *h_max) {
			*h_max = h_curr;
		}
		return;
	}

	if (TreeIsEmpty(t)) {
		return;
	}

	TreeHeightRec(TreeLeft(t), h_max, h_curr + 1);
	TreeHeightRec(TreeRight(t), h_max, h_curr + 1);
}

int TreeHeight(const Node* t) {
	if (TreeIsEmpty(t)) {
		return -1;
	}

	int h = 0;

	TreeHeightRec(t, &h, 0);

	return h;
}

int main(void) {

	ElemType a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	ElemType b[] = { 12, 4, 21, 0, 5, 18, 77, 2, 8, 9 };
	ElemType c[] = { 10, 2, 20, 6, 5, 7, 8, 4, 18, 3 };

	Node* ExampleTree1 = TreeCreateEmpty();
	Node* ExampleTree2 = TreeCreateEmpty();
	Node* ExampleTree3 = TreeCreateEmpty();

	//BST
	ExampleTree1 = TreeCreateRoot(a + 4,	//4
		TreeCreateRoot(a + 3,	//3
			TreeCreateRoot(a + 1,	//1
				TreeCreateRoot(a + 1, NULL, NULL),	//1
				TreeCreateRoot(a + 2, NULL, NULL)),	//2
			NULL),
		TreeCreateRoot(a + 7,	//7
			TreeCreateRoot(a + 5, NULL, NULL),	//5
			TreeCreateRoot(a + 8, NULL, NULL)));//8
	//NO BST
	ExampleTree2 = TreeCreateRoot(c + 0,	//10
		TreeCreateRoot(c + 1,	//2
			TreeCreateRoot(c + 3,	//6
				TreeCreateRoot(c + 7, NULL, NULL),	//4
				TreeCreateRoot(c + 8, NULL, NULL)),	//18
			TreeCreateRoot(c + 4, NULL, NULL)),	//5
		TreeCreateRoot(c + 2,	//20
			TreeCreateRoot(c + 5, NULL,	//7
				TreeCreateRoot(c + 9, NULL, NULL)),	//3
			TreeCreateRoot(c + 6, NULL, NULL)));	//8
	//BST
	ExampleTree3 = TreeCreateRoot(b + 0,	//12
		TreeCreateRoot(b + 1,	//4
			TreeCreateRoot(b + 3, NULL, //0
				TreeCreateRoot(b + 7, NULL, NULL)),  //2
			TreeCreateRoot(b + 4, NULL, //5
				TreeCreateRoot(b + 8, NULL, //8
					TreeCreateRoot(b + 9, NULL, NULL)))), //9
		TreeCreateRoot(b + 2, //21
			TreeCreateRoot(b + 5, NULL, NULL), //18
			TreeCreateRoot(b + 6, NULL, NULL))); //77

	int res = TreeHeight(ExampleTree1);
	res = TreeHeight(ExampleTree2);
	res = TreeHeight(ExampleTree3);

	TreeDelete(ExampleTree1);
	TreeDelete(ExampleTree2);
	TreeDelete(ExampleTree3);

	return 0;
}