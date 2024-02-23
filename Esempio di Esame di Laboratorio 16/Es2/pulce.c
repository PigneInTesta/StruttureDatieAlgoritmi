#include <stdlib.h>
#include <stdbool.h>

static bool IsInPos(const int* f, size_t f_size, int dist_curr) {
	for (int k = 0; k < (int) f_size; k++) {
		if (dist_curr == (int) f[k]) {
			return true;
		}
	}
	return false;
}

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size, int i, char* jump_curr, char* jump_best, size_t curr_size, int dist_curr) {
	if (dist_curr == h) {
		if (curr_size < *ret_size || *ret_size == 0) {
			*ret_size = curr_size;
			for (int y = 0; y < (int)curr_size; y++) {
				jump_best[y] = jump_curr[y];
			}
		}
		return;
	}

	if (i == n) {
		return;
	}

	for (int j = a; j >= 0 && i <= n;) {
		if (!IsInPos(f, f_size, j)) {
			if (dist_curr >= b && j - b >= 0) {
				jump_curr[i] = (int) b;
				GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, i + 1, jump_curr, jump_best, curr_size + 1, dist_curr - b);
			} else {
				jump_curr[i] = (int) a;
				GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, i + 1, jump_curr, jump_best, curr_size + 1, dist_curr + a);
			}
		}
	}

}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	char* jump_curr = malloc(n * sizeof(char));
	char* jump_best = malloc(n * sizeof(char));

	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, 0, jump_curr, jump_best, 0, 0);

	if (*ret_size == 0) {
		free(jump_curr);
		free(jump_best);
		return NULL;
	}

	free(jump_curr);
	jump_best = realloc(jump_best, (*ret_size) * sizeof(char));
	return jump_best;
}

int main(void) {
	{
		int f[] = { 12, 4, 7, 1, 15 };
		size_t f_size = sizeof(f) / sizeof(int);
		size_t ret_size = 0;
		char* res = GuidaLaPulce(f, f_size, 3, 15, 5, 9, &ret_size);
	}

	{
		int f[] = { 8, 3, 16, 6, 12, 20 };
		size_t f_size = sizeof(f) / sizeof(int);
		size_t ret_size = 0;
		char* res = GuidaLaPulce(f, f_size, 15, 13, 10, 11, &ret_size);
	}

	{
		int f[] = { 1, 6, 2, 14, 5, 17, 4 };
		size_t f_size = sizeof(f) / sizeof(int);
		size_t* ret_size = NULL;
		char* res = GuidaLaPulce(f, f_size, 16, 9, 7, 5, ret_size);
	}
}