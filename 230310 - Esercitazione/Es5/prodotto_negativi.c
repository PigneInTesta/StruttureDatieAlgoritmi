extern int ProdottoNegativi(int a, int b);

int ProdottoNegativi(int a, int b) {

	if (a == 0 || b == 0) {
		return 0;
	} else if (a == 1) {
		return b;
	} else if (b == 1) {
		return a;
	} else if (a > 0 && b > 0) {
		return a + Prodotto(a, --b);
	} else if (a < 0 && b < 0) {
		return -a + Prodotto(a, ++b);
	} else if (a < 0) {
		return a + Prodotto(a, --b);
	} else if (b < 0) {
		return -a + Prodotto(a, ++b);
	} 
}
/*
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
*/