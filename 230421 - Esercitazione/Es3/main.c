#include "stacks.h"

int main(void) {

	//Inizializzazione del nostro vettore di Stack
	Stack ese[] = { {.elements = NULL, .m = 5 }, 
					{.elements = NULL, .m = 3 }, 
					{.elements = NULL, .m = 4}};
	//Allocazione dei vettori elements
	for (size_t i = 0; i < sizeof(ese) / sizeof(Stack); i++) {
		ese[i].elements = malloc(ese[i].m * sizeof(unsigned int));
	}
	//Assegnazione degli elementi ai vettori elements
	unsigned elements_0[] = { 1, 1, 1, 2, 3 };
	unsigned elements_1[] = { 2, 3, 4 };
	unsigned elements_2[] = { 1, 4, 5, 2};

	ese[0].elements = elements_0;
	ese[1].elements = elements_1;
	ese[2].elements = elements_2;

	unsigned res = MaxSumNStack(ese, sizeof(ese) / sizeof(Stack));

	return 0;
}