#include <stdio.h>
#define CHAR (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
#define NUMBER (c >= '0' && c <= '9')
#define SPASE (c == ' ')


int main(int argc, char** argv) {
	FILE* fin, * fout;

	int count_of_lines = 1;
	int count_of_symbols = 0;

	char c;

	fin = fopen(argv[1], "r");
	fout = fopen("answer.txt", "w");

	while ((c = fgetc(fin)) != EOF) {
		if (!CHAR && !NUMBER && !SPASE)
			count_of_symbols++;
		if (c == '\n') {
			fprintf(fout, "%d symbols in %d line.\n", count_of_symbols, count_of_lines);
			count_of_symbols = 0;
			count_of_lines++;
		}
	}
	if (count_of_symbols)
		fprintf(fout, "%d symbols in %d line.\n", count_of_symbols, count_of_lines);
	return 0;
}
