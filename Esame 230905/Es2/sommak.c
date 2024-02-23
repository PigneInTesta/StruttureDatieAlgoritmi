#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void SommaKRec(int n, int k, int i, bool* vcurr, int* nsol, int sum_vcurr) {
	if (sum_vcurr == k) {
		printf("{");
		for (int j = 0; j < n; j++) {
			if (vcurr[j]) {
				printf("%d, ", j + 1);
			}
		}
		printf("}, ");
		(*nsol)++;
		return;
	}

	if (i == n) {
		return;
	}

	if (sum_vcurr + (i + 1) <= k) {
		vcurr[i] = 1;
		SommaKRec(n, k, i + 1, vcurr, nsol, sum_vcurr + (i + 1));
		vcurr[i] = 0;
	}

	vcurr[i] = 0;
	SommaKRec(n, k, i + 1, vcurr, nsol, sum_vcurr);
}

int SommaK(int n, int k) {

	int nsol = 0;
	bool* vcurr = calloc(n, sizeof(bool));

	SommaKRec(n, k, 0, vcurr, &nsol, 0);

	free(vcurr);
	return nsol;
}

//int main(void) {
//
//	int res = SommaK(6, 9);
//	puts("");
//	res = SommaK(0, 0);
//	puts("");
//
//	return 0;
//}