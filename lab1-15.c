#include <stdio.h>
#include <stdlib.h>

#define symbol !(c == ' ' || c == '\t' || c == '\n')
#define SYMBOL !(word[k] == ' ' || word[k] == '\t' || word[k] == '\n')


char* newMemory(char* word, int SIZE) {
	char *newWord = (char*)calloc(SIZE + 20, sizeof(char));

	for (int i = 0; i < SIZE; i++)
		*(newWord + i) = *(word + i);
	free(word);
	return newWord;
}

char* GetWord(FILE** fin) {
	char c;
	c = fgetc(*fin);
	while (!symbol)
		c = fgetc(*fin);
	if (c == EOF) {
		fclose(*fin);
		*fin = nullptr;
		return nullptr;
	}
	int SIZE = 20;
	int k = 0;
	char* word = (char*)calloc(SIZE, sizeof(char));
	while (symbol) {
		*(word + k) = c;
		k++;
		c = fgetc(*fin);
		if (c == EOF) {
			fclose(*fin);
			*(word + k + 1) = ' ';
			*fin = nullptr;
			return word;
		}
		if (k + 1 == SIZE) {
			word = newMemory(word, SIZE);
			SIZE += 20;
		}
	}
	*(word + k + 1) = ' ';
	return word;
}

void printword(char* word, FILE * fout) {
	int k = 0;
	if (word != nullptr) {
		while (SYMBOL) {
			fprintf(fout, "%c", word[k]);
			k++;
		}
	}
	else
		fprintf(fout, " ");
	free(word);
}

int main(int argc, char** argv) {

	char* word;
	int flag1 = 1, flag2 = 1, flag = 1;
	FILE* fin1, * fin2, * fout; 
	fout = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/answer.txt", "w");
	fin1 = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/file.TXT","r");
	fin2 = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/file1.TXT","r");

	while (flag1 || flag2) {
		if (fin1 != nullptr) {
			printword(GetWord(&fin1), fout);
		}
		else
			flag1 = 0;
		if (fin2 != nullptr) {
			printword(GetWord(&fin2), fout);
		}
		else
			flag2 = 0;
	}

	fclose(fout);
	return 0;
}
