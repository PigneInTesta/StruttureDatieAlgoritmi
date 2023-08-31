#include "tree.h"
#include <stdbool.h>

static void GetBalanceCoeffRec(const Node* t, int* p_max, int p_curr) {

	if (TreeIsEmpty(t)) {
		return;
	}

	if (TreeIsLeaf(t)) {
		if (p_curr > *p_max) {
			*p_max = p_curr;
		}
	}

	GetBalanceCoeffRec(TreeLeft(t), p_max, p_curr + 1);
	GetBalanceCoeffRec(TreeRight(t), p_max, p_curr + 1);
}

int GetBalanceCoeff(const Node* n) {
	int pl_max = 0;
	int pr_max = 0;

	GetBalanceCoeffRec(TreeLeft(n), &pl_max, 0);
	GetBalanceCoeffRec(TreeRight(n), &pr_max, 0);

	return pl_max - pr_max;
}

bool TreeIsBalanced(const Node* t) {
	if (GetBalanceCoeff(t) == -1 || GetBalanceCoeff(t) == 0 || GetBalanceCoeff(t) == 1) {
		return true;
	}
	return false;
}

int main(void) {

	ElemType a[] = { 8, 2, 1, 4, 5, 9 };

	Node* ExampleTreeA = TreeCreateEmpty();

	ExampleTreeA = TreeCreateRoot(a + 0,
		TreeCreateRoot(a + 1,
			TreeCreateRoot(a + 2, NULL, NULL),
			TreeCreateRoot(a + 3, NULL,
				TreeCreateRoot(a + 4, NULL, NULL))),
		TreeCreateRoot(a + 5, NULL, NULL));

	int res = GetBalanceCoeff(ExampleTreeA);
	bool state = TreeIsBalanced(ExampleTreeA);

	res = GetBalanceCoeff(TreeLeft(ExampleTreeA));
	state = TreeIsBalanced(TreeLeft(ExampleTreeA));

	TreeDelete(ExampleTreeA);

	return 0;
}