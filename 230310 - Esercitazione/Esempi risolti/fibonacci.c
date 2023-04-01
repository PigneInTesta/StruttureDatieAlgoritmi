static int FibonacciRec(int n) {
    //// Caso base 1 e 2
    //if (n == 0 || n == 1) {
    //    return n;
    //}

    // Caso base 1
    if (n == 0) {
        return 0;
    }
    // Caso base 2
    if (n == 1) {
        return 1;
    }

    return FibonacciRec(n - 1) + FibonacciRec(n - 2);

}

int Fibonacci(int n) {
    // Caso particolare
    if (n < 0) {
        return -1;
    }

    return FibonacciRec(n);
}

int main(void) {
    
    int f; 
    f = Fibonacci(0);
    f = Fibonacci(1);
    f = Fibonacci(2);
    f = Fibonacci(3);

    return 0;
}