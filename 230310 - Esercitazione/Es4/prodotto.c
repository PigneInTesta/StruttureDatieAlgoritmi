extern int Prodotto(int a, int b);

int ProdottoRec(int a, int b) {

	if (a == 0 || b == 0) {
		return 0;
	}
	if (a == 1) {
		return b;
	}
	if (b == 1) {
		return a;
	}

	return a + Prodotto(a, --b);

}

int Prodotto(int a, int b) {
	 
	if (a < 0 || b < 0) {
		return -1;
	}

	return ProdottoRec(a, b);
}
/*
int main(void) {

	Prodotto(-1, 0);
	Prodotto(0, -1);
	Prodotto(0, 0);
	Prodotto(0, 9);
	Prodotto(9, 0);
	Prodotto(9, 1);
	Prodotto(9, 2);
	Prodotto(6, 6);

	return 0;


}
*/