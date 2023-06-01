#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, int i, bool *vcurr, int vcurr_sum, int vcurr_size, bool *vbest, int *vbest_size) {

	if (i == (int) pacchi_size) {
		if (vcurr_size > (*vbest_size)) {
			memcpy(vbest, vcurr, pacchi_size);
			(*vbest_size) = vcurr_size;
		}
		return;
	}

	vcurr[i] = false;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vcurr_sum, vcurr_size, vbest, vbest_size);

	if (vcurr_sum <= p) {
		vcurr[i] = true;
		BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vcurr_sum + pacchi[i], vcurr_size + 1, vbest, vbest_size);
		vcurr[i] = false;
	}

}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {

	bool* vcurr = calloc((int) pacchi_size, sizeof(bool));
	bool* vbest = calloc((int) pacchi_size, sizeof(bool));
	
	int vbest_size = 0;
	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, 0, 0, vbest, &vbest_size);

	for (int j = 0; j < (int)pacchi_size; ++j) {
		printf("%d ", vbest[j]);
	}

	free(vcurr);
	free(vbest);
}

//int main(void) {
//
//	int pacchi_a[] = { 10, 11, 1, 3, 3 };
//	size_t dim_a = sizeof(pacchi_a) / sizeof(int);
//	BabboNatale(pacchi_a, dim_a, 20);
//
//	return 0;
//}