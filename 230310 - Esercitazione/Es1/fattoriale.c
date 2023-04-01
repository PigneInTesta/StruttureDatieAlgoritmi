extern unsigned long long Fattoriale(int n);

static unsigned long long FattorialeRec(int n) {

	if (n == 0 || n == 1) {
		return 1;
	}

	return Fattoriale(n - 1) * n;

}

unsigned long long Fattoriale(int n) {

	if (n < 0) {
		return 0;
	}

	return FattorialeRec(n);
}

/*
int main(void) {

	Fattoriale(-1);
	Fattoriale(0);
	Fattoriale(1);
	Fattoriale(2);
	Fattoriale(3);

	return 0;
}
*/