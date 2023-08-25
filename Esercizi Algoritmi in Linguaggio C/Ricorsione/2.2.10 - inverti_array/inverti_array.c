#include <stdlib.h>

void InvertiArrayRec(int* arr, size_t size, int in, int out) {

	if (size == 1 || size == 0) {
		return;
	}

	int x = arr[out];
	arr[out] = arr[in];
	arr[in] = x;

	return InvertiArrayRec(arr, size - 2, in + 1, out - 1);
}

void InvertiArray(int* arr, size_t size) {
	return InvertiArrayRec(arr, size, 0, size - 1);
}

int main(void) {
	
	int num1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	InvertiArray(num1, 9);

	int num2[] = { 1, 2, 3, 4 };
	InvertiArray(num2, 4);

	return 0;
}