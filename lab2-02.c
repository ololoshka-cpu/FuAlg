#include <stdio.h>
#include <stdlib.h>

#define digit (c>='0' && c<='9')

int main(int argc, char** argv) {
	FILE* fin = nullptr;
	int* arr = (int*)calloc(128, sizeof(int));
	int k = 0;
	int count = 0;
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
			if (x % 2 == 0)
				count++;
			x = 0;
			k++;
		}
		if (k == 182)
			break;
	}
	int* _arr = (int*)calloc(count, sizeof(int));
	x = 0;
	for (int i = 0; i < k; i++) 
		if (*(arr + i) % 2 == 0) {
			*(_arr + x) = *(arr + i);
			x++;
			//printf("%d ",*(_arr + x - 1));
		}
	return 0;
}
