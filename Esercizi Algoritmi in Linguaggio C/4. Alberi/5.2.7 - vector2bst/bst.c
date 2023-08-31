#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

Node* Vector2Bst(const ElemType* v, size_t v_size) {

	Node* t = TreeCreateEmpty();

	if (v_size == 0) {
		return t;
	}

	t = TreeCreateRoot(&v[0], NULL, NULL);

	for (size_t i = 1; i < v_size; i++) {
		Node* tmp = t;

		while (1) {
			if (ElemCompare(TreeGetRootValue(tmp), &v[i]) > 0) {
				if (TreeIsEmpty(TreeLeft(tmp))) {
					tmp->left = TreeCreateRoot(&v[i], NULL, NULL);
					break;
				} else {
					tmp = TreeLeft(tmp);
				}
			} else if (ElemCompare(TreeGetRootValue(tmp), &v[i]) < 0) {
				if (TreeIsEmpty(TreeRight(tmp))) {
					tmp->right = TreeCreateRoot(&v[i], NULL, NULL);
					break;
				} else {
					tmp = TreeRight(tmp);
				}
			} else {
				//il nodo è già presente nell'albero
				break;
			}
		}
	}

	return t;
}

int main(void) {
	
	const ElemType a[] = { 8, 2, 4, 5, 2, 1, 9 };					//			8
	size_t dim_a = sizeof(a) / sizeof(ElemType);					//		   / \
																	//		  2   9
	Node* res = Vector2Bst(a, dim_a);								//		 / \
																	//		1	4
	TreeDelete(res);												//			 \
																	//            5
	return 0;													
}