#include "fdi_check.h"

int ProdottoNegativi(int a, int b) {
	// Caso base
	if (b == 0) {
		return 0;
	}

	if (b > 0) {
		return a + ProdottoNegativi(a, --b);
	}
	else {
		return -a + ProdottoNegativi(a, ++b);
	}
}

int main(void) {

	Prodotto(-1, 0);
	Prodotto(0, -1);
	Prodotto(0, 0);
	Prodotto(0, 9);
	Prodotto(9, 0);
	Prodotto(-9, 1);
	Prodotto(9, -2);
	Prodotto(-6, 6);
	Prodotto(-6, -6);

	return 0;

}