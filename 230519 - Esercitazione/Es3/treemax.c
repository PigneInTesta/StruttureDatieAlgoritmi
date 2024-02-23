#include "tree.h"
#include <stdlib.h>
#include <limits.h>

const ElemType* BstTreeMax(const Node* n) {

	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType* max = TreeGetRootValue(n);

	while (!TreeIsEmpty(n)) {
		n = TreeRight(n);
		if (TreeIsLeaf(n) || n->left == NULL || n->right == NULL) {
			max = &n->value;
			break;
		}
		max = TreeGetRootValue(n);
	}

	return max;
}

static const ElemType* TreeMaxRec(const Node* n, const ElemType* max) {

	if (TreeIsEmpty(n)) {
		return max;
	}

	if (ElemCompare(TreeGetRootValue(n), max) > 0) {
		max = TreeGetRootValue(n);
	}
	
	max = TreeMaxRec(TreeLeft(n), max);
	max = TreeMaxRec(TreeRight(n), max);

	return max;
}


const ElemType* TreeMax(const Node* n) {
	if (TreeIsEmpty(n)) {
		return NULL;
	}

	const ElemType i = INT_MIN;
	return TreeMaxRec(n, &i);
}
/*
static Node* Vector2TreeRec(const ElemType* v, size_t v_size, size_t i) {
	if (i >= v_size || v[i] == INT_MAX) {
		return NULL;
	}

	Node* l = Vector2TreeRec(v, v_size, 2 * i + 1);
	Node* r = Vector2TreeRec(v, v_size, 2 * i + 2);

	return TreeCreateRoot(&v[i], l, r);
}

static Node* Vector2Tree(const ElemType* v, size_t v_size) {
	return Vector2TreeRec(v, v_size, 0);
}

int main(void) {

	ElemType a[] = { 12, 4, 21, 0, 5, 18, 77, INT_MAX, 2, INT_MAX, 8, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 9, INT_MAX , INT_MAX, INT_MAX , INT_MAX , INT_MAX };
	ElemType b[] = { 15, 10, 21, 3, 12, 18, 27, 1, 8, 11, 14, 16, 19, 22, 30};
	ElemType c[] = { 4, 1, 7, -4, 2, 5, INT_MAX, INT_MAX, 1, INT_MAX, 3, INT_MAX, INT_MAX };

	size_t dim_a = sizeof(a) / sizeof(ElemType);
	size_t dim_b = sizeof(b) / sizeof(ElemType);
	size_t dim_c = sizeof(c) / sizeof(ElemType);
	Node* Tree1 = Vector2Tree(a, dim_a);
	Node* Tree2 = Vector2Tree(c, dim_c);
	Node* TreeBST = Vector2Tree(b, dim_b);

	const ElemType* res1 = BstTreeMax(TreeBST);
	const ElemType* res2 = BstTreeMax(Tree1);
	const ElemType* res3 = TreeMax(TreeBST);
	const ElemType* res4 = TreeMax(Tree1);
	const ElemType* res5 = BstTreeMax(Tree2);

	free(Tree1);
	free(Tree2);
	free(TreeBST);

	return 0;
}
*/