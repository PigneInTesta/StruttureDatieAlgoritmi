#include <stdlib.h>
#include <ctype.h>

static int FindPosMax(int *v, size_t v_size) {
	int max_pos = 0;
	for (int j = 0; j <= (int) v_size; j++) {
		if (v[max_pos] < v[j]) {
			max_pos = j;
		}
	}

	return max_pos;
}

static void flip(int *v, int i) {
	int first = 0;
	while (first <= i) {
		int tmp = v[i];
		v[i] = v[first];
		v[first] = tmp;
		first++;
		i--;
	}
}

void PancakeSort(int* v, size_t v_size) {
	
	size_t curr_size = v_size;

	while (curr_size > 1) {
		int pos_max = FindPosMax(v, curr_size - 1);
		flip(v, pos_max);
		flip(v, curr_size - 1);
		curr_size--;
	}
}

//int main(void) {
//
//	int v1[] = { 2, 3, 1 };
//	size_t dim_v1 = sizeof(v1) / sizeof(int);
//	PancakeSort(v1, dim_v1);
//
//	int v2[] = { 3, 6, 2, 9, 0, 7, 1, -4, 8, 10, 45, 100, 23, 88, -12, 37, -51 };
//	size_t dim_v2 = sizeof(v2) / sizeof(int);
//	PancakeSort(v2, dim_v2);
//
//	return 0;
//}