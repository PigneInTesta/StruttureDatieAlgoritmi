#include "torrecartoni.h"

int main(void) {

	Cartone c1[] = { {.p = 10, .a = 20, .l = 40}, {.p = 10, .a = 10, .l = 8}, {.p = 9, .a = 3, .l = 5} };
	Cartone c2[] = { {.p = 25, .a = 20, .l = 40}, {.p = 10, .a = 10, .l = 12}, {.p = 9, .a = 3, .l = 5} };
	TorreCartoni(c1, 3);
	TorreCartoni(c2, 3);

	return 0;
}