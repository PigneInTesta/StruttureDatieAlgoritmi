#include "somma.h"

 static int SommaFinoARec(int n) {	// Non serve includerla nel file.h perchè non DEVE essere utilizzata nel main, è solo una funzione ausiliaria

	// Caso Base
	if (n == 1) {
		return 1;
	}

	return SommaFinoA(n - 1) + n;
}

int SommaFinoA(int n) {

	// Caso particolare
	if (n <= 0) {
		return -1;
	}

	return SommaFinoARec(n);

}