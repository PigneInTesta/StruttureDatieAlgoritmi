#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

static void ValidTimesRec(uint8_t n, int i, int k, int ore_tot, int minuti_tot, int* orologio, bool* vcurr, size_t dim_orologio) {
	if (k == n) {
		if (ore_tot != 0 || minuti_tot != 0) {
			if (ore_tot / 10 != 0 && minuti_tot / 10 != 0) {
				printf("%d:%d, ", ore_tot, minuti_tot);
			} else if (ore_tot / 10 == 0 && minuti_tot / 10 != 0) {
				printf("0%d:%d, ", ore_tot, minuti_tot);
			} else if (ore_tot / 10 != 0 && minuti_tot / 10 == 0) {
				printf("%d:0%d, ", ore_tot, minuti_tot);
			} else {
				printf("0%d:0%d, ", ore_tot, minuti_tot);
			}
			return;
		}
	}

	if (i == (int)dim_orologio) {
		return;
	}

	vcurr[i] = 1;
	if (i <= 5) {
		if (minuti_tot + orologio[i] <= 59) {
			ValidTimesRec(n, i + 1, k + 1, ore_tot, minuti_tot + orologio[i], orologio, vcurr, dim_orologio);
		}
	} else if (i > 5) {
		if (ore_tot + orologio[i] <= 23) {
			ValidTimesRec(n, i + 1, k + 1, ore_tot + orologio[i], minuti_tot, orologio, vcurr, dim_orologio);
		}
	}

	vcurr[i] = 0;
	ValidTimesRec(n, i + 1, k, ore_tot, minuti_tot, orologio, vcurr, dim_orologio);
}

void ValidTimes(uint8_t n) {
	if (n > 11) {
		return;
	}

	int orologio[] = { 1, 2, 4, 8, 16, 32, 1, 2, 4, 8, 16};
	size_t dim_orologio = sizeof(orologio) / sizeof(int);

	bool* orario = calloc(dim_orologio, sizeof(bool));

	ValidTimesRec(n, 0, 0, 0, 0, orologio, orario, dim_orologio);

	free(orario);
}

//int main(void) {
//
//	ValidTimes(1);
//	puts("");
//
//	ValidTimes(9);
//	puts("");
//
//	return 0;
//}