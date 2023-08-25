#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool IsPalindromoRec(const char* s, size_t o, size_t p) { 

	if (o > p || s == "") {
		return true;
	}

	if (s[o] == s[p]) {
		return IsPalindromoRec(s, o + 1, p - 1);
	}

	return false;

}

bool IsPalindromo(const char* s) {
	
	if (s == NULL) {
		return false;
	}

	return IsPalindromoRec(s, 0, strlen(s) - 1);
}

int main(void) {

	bool res = IsPalindromo(NULL);
	res = IsPalindromo("anna");
	res = IsPalindromo("osso");
	res = IsPalindromo("ossesso");
	res = IsPalindromo("franco");
	res = IsPalindromo("");
	res = IsPalindromo("ziopera");
	res = IsPalindromo("angela");


}