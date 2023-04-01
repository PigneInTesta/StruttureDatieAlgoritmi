#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int AToIRec(const char* str, size_t i, int num) {

	if (str[0] == '+' || str[0] == '0' || str[0] == '-') {
		if (i == strlen(str) - 1) {
			if (str[0] == '+' || str[0] == '0') {
				num *= 1;
			} else if (str[0] == '-') {
				num *= -1;
			}
			return num;
		}
	} else {
		if (i == strlen(str)) {
			if (str[0] == '+' || str[0] == '0') {
				num *= 1;
			} else if (str[0] == '-') {
				num *= -1;
			}
			return num;
		}
	}
	

	if (str[0] == '+' || str[0] == '-' || (str[i] >= '0' && str[i] <= '9')) {
		if (str[0] == '+' || str[0] == '0' || str[0] == '-') {
			num += (int)((str[i + 1] - '0') * pow(10, strlen(str) - 2 - i));
		} else {
			num += (int)((str[i] - '0') * pow(10, strlen(str) - 1 - i));
		}
		return AToIRec(str, i + 1, num);
	}

	return 0;
	
}

int AToI(const char* str) {

	if (str == NULL) {
		return 0;
	}

	return AToIRec(str, 0, 0);
}

int main(void) {

	int res = AToI("42");
	res = AToI("+42");
	res = AToI("4-2");
	res = AToI("042");
	res = AToI("a42");
	res = AToI(" 42");
	res = AToI("+ 42");

	return 0;
}