#include "tree.h"
#include <stdlib.h>
#include <stdbool.h>

//La funzione che richiede di implementare l'esercizio funziona ma OLJ da memory leak
static ElemType* MakeSumOfSons(const Node* r, const Node* l) {
	ElemType *sum = malloc(sizeof(ElemType));	//dovuto a questo

	if (r == NULL) {
		(*sum) = 0;
	} else {
		(*sum) = r->value;
	}

	if (l == NULL) {
		(*sum) += 0;
	} else {
		(*sum) += l->value;
	}

	return sum;
}

static bool IsDominant(const Node* t) {
	if (!TreeIsLeaf(t) && ElemCompare(TreeGetRootValue(t), MakeSumOfSons(TreeRight(t), TreeLeft(t))) > 0) {
		return true;
	}
	return false;
}

static int CountDominantRec(const Node* t, int *flag) {
	if (TreeIsEmpty(t)) {
		return (*flag);
	}

	if (IsDominant(t)) {
		(*flag)++;
	}
	
	TreeGetRootValue(t);
	CountDominantRec(TreeLeft(t), flag);
	CountDominantRec(TreeRight(t), flag);
}

int CountDominant(const Node* t) {
	int n = 0;
	return CountDominantRec(t, &n);
}
/*
static Node *Vector2TreeRec(const ElemType *v, size_t v_size, size_t i) {
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

	ElemType n[] = { 12, 4, 21, 0, 2, 5, 18, 77, 8, 9, INT_MAX , INT_MAX, INT_MAX , INT_MAX , INT_MAX };

	size_t dim = sizeof(n) / sizeof(ElemType);
	Node* ExampleTree1 = Vector2Tree(n, dim);

	int res = CountDominant(ExampleTree1);

	return 0;
}
*/