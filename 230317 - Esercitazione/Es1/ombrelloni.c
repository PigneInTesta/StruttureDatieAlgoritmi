#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void OmbrelloniRec(int k, int n, bool *vcurr, int i, int *nsol, int cnt) {
	
	if (cnt == k) {
		(*nsol)++;
		printf("%4d) ", *nsol);
		for (int j = 0; j < n; ++j) {
			printf("%d ", vcurr[j]);
		}
		puts("");
		return;
	}

	if (i == n) {
		return;
	}

	vcurr[i] = false;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt);

	if ((!vcurr[i - 1] && !vcurr[i]) || i == 0) {
		vcurr[i] = true;
		OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt + 1);
	}
	
	vcurr[i] = false;
	cnt = 0;
}

int Ombrelloni(int k, int n) {

	if (k < 0 || n < 0) {
		return 0;
	}

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;

	OmbrelloniRec(k, n, vcurr, 0, &nsol, 0);

	free(vcurr);
	return nsol;
}

//int main(void) {
//
//	int nsol = Ombrelloni(2, 4);
//	nsol = Ombrelloni(4, 4);
//	return 0;
// }