extern int Divisione(int a, int b);

int DivisioneRec(int a, int b, int i) {

	if ((a - b) >= 0) {
		i++;
		return DivisioneRec(a - b, b, i);
	}

	return i;  
}

int Divisione(int a, int b) {
	 
	if (a < 0 || b < 0 || b == 0) {
		return -1;
	}

	DivisioneRec(a, b, 0);
}
/*
int main(void) {
	 
	Divisione(-1, 1);
	Divisione(1, -1);
	Divisione(0, 0);
	Divisione(6, 0);
	Divisione(0, 6);
	Divisione(6, 3);
	Divisione(4, 2);
	Divisione(3, 2);
	Divisione(7, 3);
	Divisione(3, 6);
	Divisione(7, 3);

	return 0;
}
*/