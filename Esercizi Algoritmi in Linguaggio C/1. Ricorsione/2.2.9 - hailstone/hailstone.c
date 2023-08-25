#include <stdlib.h>
#include <stdio.h>

size_t HailstoneRec(int n, size_t i) {

	if (n == 1) {
		i++;
		printf("%i\n", n);
		return i;
	} else if(n % 2 == 0) {
		printf("%i, ", n);
		n /= 2;
	} else {
		printf("%i, ", n);
		n = 3 * n + 1;
	}

	return HailstoneRec(n, i + 1);

}

size_t Hailstone(int n) {

	if (n <= 0) {
		return 0;
	}

	return HailstoneRec(n, 0);
}

int main(void) {

	size_t res = Hailstone(-2);
	res = Hailstone(0);
	res = Hailstone(1);
	res = Hailstone(5);		//5, 16, 8, 4, 2, 1 res = 6
	res = Hailstone(11);	//11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2, 1 res = 15
}