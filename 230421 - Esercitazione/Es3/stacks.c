#include "stacks.h"

static unsigned MakeSum(Stack stacks) {
	unsigned sum = 0;
	for (size_t j = 0; j < stacks.m; j++) {
		sum += stacks.elements[j];
	}
	return sum;
}

static unsigned FindMax(Stack* stacks, size_t dim, size_t* pos) {
	unsigned MinStacks = 0;
	for (size_t i = 0, sum = 0; i < dim; i++) {
		sum = MakeSum(stacks[i]);
		if (i == 0) {
			MinStacks = sum;
			(*pos) = i;
		} else if (sum < MinStacks) {
			MinStacks = sum;
			(*pos) = i;
		}
		sum = 0;
	}
	return MinStacks;
}

unsigned MaxSumNStack(Stack* stacks, size_t n) {

	unsigned max = 0;
	for (size_t j = 0, ref = 0, cur = 1; j < n;) {
		 max = FindMax(stacks, n, &ref);
		 if (j != (ref) && MakeSum(stacks[j]) != max) {
			while (MakeSum(stacks[j]) > max) {
				stacks[j].elements[stacks[j].m - cur] = 0;
				cur++;
			}
			ref = j;
			j = 0;
			cur = 1;
			continue;
		 }
		 j++;
	}

	return max;
}