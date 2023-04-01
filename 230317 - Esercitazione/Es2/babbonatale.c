#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, unsigned int i, bool* vcurr, bool* vbest, int* max, int cnt, int sum) {
	
	if (i == pacchi_size) {
	
		if ((*max) < cnt) {
			for (int j = 0; i < pacchi_size; i++) {
				printf("%d", vbest[i]);
			}
		}
		(*max) = 0;
		for (int i = 0; i < pacchi_size; i++) {
			vbest[i] = vcurr[i];
			if (vbest[i] == 1) {
				(*max)++;
			}
		}
		return;
	}

	if (sum > p) {
		return;
	}

	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt, sum);

	sum += pacchi[i];
	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, i + 1, vcurr, vbest, max, cnt + 1, sum);
}

void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	 
	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* vbest = calloc(pacchi_size, sizeof(bool));
	int max = 0;

	BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, &max, 0, 0);

	free(vcurr);
	free(vbest);
}

int main(void) {

	int pacchi[] = { 10, 11, 1, 3, 3 };
	BabboNatale(pacchi, 5, 20);

	return 0;
}