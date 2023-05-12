#include "gioielli.h"

int main(void) {

	size_t ret_size = 0;
	Gioiello * res = CompraGioielli("gioielli_1.txt", 130, &ret_size);
	res = CompraGioielli("gioielli_2.txt", 200, &ret_size);
	free(res);

	return 0;
}