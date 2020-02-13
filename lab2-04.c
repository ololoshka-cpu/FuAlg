#include <stdio.h>
#include <stdlib.h>

void capitalase(char* string);

int main(int argc, char** argv) {
	char str[] = "ynsdksneufh47oi23u09x   3482398wjsuw72\0";

	capitalase(str);

	printf(str);

	return 0;
}

void capitalase(char* string){
	int k = 0;
	while (*(string + k) != '\0') {
		if (k % 2 == 1 && *(string + k) >= 97 && *(string + k) <= 122)
			*(string + k) -= 32;
		k++;
	}
}
