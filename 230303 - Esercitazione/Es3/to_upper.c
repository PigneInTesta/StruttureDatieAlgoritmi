#include <string.h>
#include <stdlib.h>

void ToUpper(char* str) {

	if (str == NULL) {
		return;
	}

	for (size_t i = 0; i <= strlen(str); ++i) {		//str + i : indirizzo di memoria di str + i
		if (*str + i >= 'a' && *str + i <= 'z') {
			*(str + i) = *(str + i) - ('a' - 'A');
		}
	}
}

/*
#include "to_upper.h"

int main(void) {

	ToUpper(NULL);
	ToUpper("ciao");
	ToUpper("SalvEse");

	return 0;
}
*/