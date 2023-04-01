#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ContaOccorrenze(const char* filename, const char* str) {

	if (str == NULL) {
		return 0;
	}

	FILE* f = fopen(filename, "r");

	if (f == NULL || ferror(f)) {
		return 0;
	}

	char s1[100];

	int occ = 0;

	while (feof(f) == 0) {
		fscanf(f, "%s", s1);

		if (strcmp(s1, str) == 0) {
			occ++;
		}
	}

	fclose(f);
	return occ;
}

/*
int main(void) {
	
	int res = ContaOccorrenze("file1.txt", "parola");

	return 0;
}
*/