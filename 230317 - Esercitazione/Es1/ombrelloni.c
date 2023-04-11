#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static void OmbrelloniRec(int k, int n, bool* vcurr, int i, int* nsol, int cnt) {

	if (i == n) {
		cnt = vcurr[0];
		for (int j = 1; j < n; j++) {
			if (vcurr[j]) {							// == 1 si può omettere
				cnt++;
			}

			if (vcurr[j] == 1 && vcurr[j - 1] == 1) {		// == 1 si può omettere
				return;
			}
		}

		if (cnt == k) {
			(*nsol)++;
			printf("%4d) ", *nsol);
			for (int j = 0; j < n; ++j) {
				printf("%d ", vcurr[j]);
			}
			puts("");
		}

		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt);

	vcurr[i] = 1;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, cnt);
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

/*
int main(void) {

	int nsol = Ombrelloni(2, 4);
	nsol = Ombrelloni(4, 4);
	return 0;
 }
 */
 