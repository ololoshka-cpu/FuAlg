#include <stdio.h>
#include <stdlib.h>
char* strcat(char* str1, char* str2);
int length(char* string);

int main(int argc, char** argv) {
	char str1[] = "nhdn";
	char str2[] = "hdejdw7";
	char* result;

	result = strcat(str1, str2);
	printf(result);
	return 0;
}

char* strcat(char* str1, char* str2) {
	int i = length(str1);
	int j = length(str2);
	char* result = nullptr;
	while (result == nullptr)
		result = (char*)calloc(i + j + 1, sizeof(char));	
	for (int k = 0; k < i; k++) {
		*(result + k) = *(str1 + k);
	}
	for (int k = i; k < i + j; k++)
		*(result + k) = *(str2 + k - i);
	*(result + i + j) = '\0';
	return result;
}

int length(char* string) {
	int k = 0;
	while (*(string + k) != '\0')
		k++;
	return k;
}
