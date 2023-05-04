#include "vettore.h"

int main(void){

	Vector* res = VectorRead("input_int_01.txt");
	res = VectorReadSorted("input_int_01.txt");
	res = VectorRead("vuoto.txt");

	return 0;
}