#include "vettore.h"

int main(void) {

	struct vettore esempio = { .data = NULL, .size = 0 };

	int data[] = { 1, 2, 3, 4, 5 };
	esempio.data = data;

	Push(&esempio, 6);
	int res = Pop(&esempio);
	
	return 0;
}