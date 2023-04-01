extern int Fibonacci(int n);

int FibonacciRec(int n) {
	// Caso base 1
	if (n == 0) {
		return 0;
	}
	// Caso base 2
	else if (n == 1) {
		return 1;
	}

	return FibonacciRec(n - 1) + FibonacciRec(n - 2);  //Non è una ricorsione lineare
}

int Fibonacci(int n) {
	// Caso particolare
	if (n < 0) {
		return -1;
	}
	
	return FibonacciRec(n);
}


int main(void) {

	Fibonacci(-1);
	Fibonacci(0);
	Fibonacci(1);
	Fibonacci(2);	// 1 + 0 = 1
	Fibonacci(3);	// 1 + 1 = 2
	Fibonacci(4);	// 2 + 1 = 3
	Fibonacci(5);	// 3 + 2 = 5
}
