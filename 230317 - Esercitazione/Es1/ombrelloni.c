#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void OmbrelloniRec(int k, int n, bool *vcurr, int i, int *nsol, int cnt) {
	if (i == n) {
		for (int j = 0; j < n; j++) {
			if (vcurr[j] == 1) {
				cnt++;
			}
		}

		if (cnt == k) {
			for (int y = 0; y < n; y++) {
				if (vcurr[y] == 0) {
					continue;
					/*
					if (vcurr[y + 1] == 1 && vcurr[y + 2] != 1) {
						(*nsol)++;
						printf("%*i)", n, nsol[0]);
						for (int g = 0; g < n; g++) {
							printf(" %i", vcurr[g]);
						}
						printf("\n");
						break;
					}
					*/
				} else if (vcurr[y] == 1) {
					if (vcurr[y + 1] != 1 && (y + 1) < n) {
						(*nsol)++;
						printf("%*i)", n, nsol[0]);
						for (int g = 0; g < n; g++) {
							printf(" %i", vcurr[g]);
						}
						printf("\n");
						break;
					}
				}
			}
		}
		cnt = 0;

		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(n, k, vcurr, i + 1, nsol, cnt);

	vcurr[i] = 1;
	OmbrelloniRec(n, k, vcurr, i + 1, nsol, cnt);
}

int Ombrelloni(int k, int n) {

	if (k < 0 || n < 0) {
		return 0;
	}

	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;

	OmbrelloniRec(k, n, vcurr, 0, &nsol, 0);

	if (nsol == 0) {
		return 0;
	}

	free(vcurr);
	return nsol;
}

int main(void) {

	int nsol = Ombrelloni(2, 4);
	nsol = Ombrelloni(4, 4);
	return 0;
 }
 