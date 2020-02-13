#include <stdio.h>
#include <stdlib.h>

#define digit (c>='0' && c<='9')

int main(int argc, char** argv) {
	FILE* fin = nullptr;
	int* arr = (int*)calloc(128, sizeof(int));
	int k = 0;
	char c;
	int x = 0;
	fin = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/file.TXT", "r");
	while ((c = fgetc(fin)) != EOF) {
		while (digit) {
			x = x * 10 + c - 48;
			c = fgetc(fin);
		}
		if (x != 0) {
			*(arr + k) = x;
			x = 0;
			k++;
		}
		if (k == 182)
			break;
	}
	int* _arr = (int*)calloc(k / 2, sizeof(int));
	for (int i = 0; i < k / 2; i++) {
		*(_arr + i) = *(arr + 2 * i + 1);
		printf("%d ", *(_arr + i));
	}


	
	return 0;
}
