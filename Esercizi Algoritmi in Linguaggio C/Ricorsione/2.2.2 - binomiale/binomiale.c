static double BinomialeRec(unsigned int n, unsigned int k) {
	
	if (k == 0 || k == n) {
		return 1;
	}

	return BinomialeRec(n - 1, k - 1) + BinomialeRec(n - 1, k);
}

double Binomiale(unsigned int n, unsigned int k) {
	if (n == 0 || k > n) {
		return -1;
	}

	return BinomialeRec(n, k);
}

int main(void) {

	double s = Binomiale(0, 8);
	s = Binomiale(2, 8);
	s = Binomiale(2, 0);
	s = Binomiale(2, 2);
	s = Binomiale(3, 2);	// s = 3
	s = Binomiale(9, 4);	// s = 126

	return 0;
}