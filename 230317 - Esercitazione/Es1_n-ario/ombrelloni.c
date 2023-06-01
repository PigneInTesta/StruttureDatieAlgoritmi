#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void OmbrelloniRec(int k, int n, int i, int *vcurr, int cnt, int *nsol) {

	if (cnt == k) {
		(*nsol)++;
		printf("%4d) ", *nsol);
		for (int j = 0, pos = 0; j < n; ++j) {
			if (vcurr[pos] == j) {
				printf("1 ");
				pos++;
			} else {
				printf("0 ");
			}
		}
		puts("");
		return;
	}

	for (int j = 0; j < n; ++j) {
		if (i == 0 || j >= vcurr[i - 1] + 2) {
			vcurr[i] = j;
			OmbrelloniRec(k, n, i + 1, vcurr, cnt + 1, nsol);
		}
	}
}

int Ombrelloni(int k, int n) {
	if (k < 0 || n < 0) {
		return 0;
	}

	int* vcurr = calloc(k, sizeof(int));

	int nsol = 0;
	OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);

	free(vcurr);

	return nsol;
}

//int main(void) {
//	
//	int res = Ombrelloni(2, 4);
//	
//	return 0;
//}