#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define digit (c >= 48 && c <= 57 || c>= 65 && c <= 90 || c >= 97 && c <= 122)

char* GetNumber(FILE** fin);
char* NewMemory(char* number, int SIZE);
char Maximum(char* number);

int main(int argc, char** argv) {
	FILE* fin, * fout;
	char* number = nullptr;
	int count = 0;
	int flag = 1;
	char Max;
	int CC;
	int answer = 0;

	fout = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/answer.txt", "w");
	fin = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/file.TXT", "r");

	while (flag) {
		if (fin != nullptr)
			number = GetNumber(&fin);
		else {
			flag = 0;
			return 0;
		}

		if (number == nullptr)
			return 0;

		Max = Maximum(number);
		if (Max <= 57)
			CC = Max - 47;
		else
			CC = Max - 53;
		while (*(number + count) != ' ')
			count++;
		
		int k = 0;
		
		while (*(number + k) != ' ') {
			if (*(number + k) <= 57)
				answer += (*(number + k) - 48) * (int)pow((double)CC, (double)(count - k - 1));
			else
				answer += (*(number + k) - 54) * (int)pow((double)CC, (double)(count - k - 1));
			k++;
		}
		
		fprintf(fout, "(%d - %dns)  ", answer, CC);
		free(number);
		count = 0;
		answer = 0;
	}
	fclose(fout);
	return 0;
}

char* GetNumber(FILE** fin) {
	char c;
	c = fgetc(*fin);
	if (c == EOF) {
		fclose(*fin);
		*fin = nullptr;
		return nullptr;
	}
	while (!digit) {
		c = fgetc(*fin);
		if (c == EOF) {
			fclose(*fin);
			*fin = nullptr;
			return nullptr;
		}
	}

	int SIZE = 20;
	char* number = (char*)calloc(SIZE, sizeof(char));
	int k = 0;
	while (digit) {
		*(number + k) = c;
		if (k + 1 == SIZE) {
			number = NewMemory(number, SIZE);
			SIZE += 20;
		}
		k++;
		c = fgetc(*fin);
	}
	if (c == EOF) {
		fclose(*fin);
		*fin = nullptr;
	}
	*(number + k) = ' ';
	return number;
}

char* NewMemory(char* number,int SIZE) {
	char* newnumber = (char*)calloc(SIZE + 20, sizeof(char));
	for (int i = 0; i < SIZE; i++)
		*(newnumber + i) = *(number + i);
	free(number);
	return newnumber;
}

char Maximum(char* number) {
	int k = 0;
	while (*(number + k) != ' ') {
		if (*(number + k) >= 97)
			*(number + k) = *(number + k) - 32;
		k++;
	}
	k = 0;
	char Max = 48;
	while (*(number + k) != ' ') {
		if (*(number + k) > Max)
			Max = *(number + k);
		k++;
	}
	return Max;
}
