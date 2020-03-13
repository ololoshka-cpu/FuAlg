#include <stdio.h>
#include <string.h>

void reverse(char* str);

int main(int argc, char** argv) {
	char str[] = "abcdefghys6g3";
	puts(str);

	reverse(str);
	puts(str);

	return 0;
}

void reverse(char* str) {
	int k = strlen(str);
	int tmp;
	
	for (int i = 0; i < k / 2; i++) {
		tmp = str[i];
		str[i] = str[k - i - 1];
		str[k - i - 1] = tmp;
	}
}
