#include <stdio.h>
#include <stdlib.h>

#define symbol !(c == ' ' || c == '\t' || c == '\n')

char* newMemory(char* word, int SIZE);
void PrintWord(char* word, FILE* fout, int k);
char* GetWord(FILE** fin);

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

char* newMemory(char* word, int SIZE) {
	char* newWord = (char*)calloc(SIZE + 20, sizeof(char));

	for (int i = 0; i < SIZE; i++)
		*(newWord + i) = *(word + i);
	free(word);
	return newWord;
}

void PrintWord(char *word, FILE * fout, int k) {
	int i = 0;
	if (k % 5 == 0)
		while (*(word + i + 1) != ' ') {
			fprintf(fout, "%d", *(word + i));
			i++;
		}
	else if (k % 2 == 0)
		while (*(word + i + 1) != ' ') {
			if (*(word + i) >= 65 && *(word + i) <= 90)
				fprintf(fout, "%c", (*(word + i) + 32));
			else
				fprintf(fout, "%c", *(word + i));
			i++;
		}
	else
		while (*(word + i + 1) != ' ') {
			fprintf(fout, "%c", *(word + i));
			i++;
		}
	fprintf(fout, " ");
}
int main(int argc, char** argv) {
	FILE* fin, * fout;
	int flag = 1;
	int k = 1;

	fout = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/answer.txt", "w");
	fin = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/file.TXT", "r");

	while (flag) {
		PrintWord(GetWord(&fin), fout, k);
		if (fin == nullptr)
			flag = 0;
		k++;
	}
	fclose(fout);
	return 0;
}
