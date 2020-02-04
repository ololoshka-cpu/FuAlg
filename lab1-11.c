#include <stdio.h>

int main(int argc, char** argv) {

	FILE* Fin, * Fout;
	char c;
	int count_of_chars = 0;
	int count_of_lines = 1;

	Fin = fopen(argv[1], "r");
	Fout = fopen("C:/Users/Andrew's PC/Documents/answer.txt", "w");

	

	while ((c = fgetc(Fin)) != EOF) {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			count_of_chars++;
		if (c == '\n') {
			fprintf(Fout, "%d chars in %d line\n", count_of_chars, count_of_lines);
			count_of_chars = 0;
			count_of_lines++;
		}
	}
	if (count_of_chars)
		fprintf(Fout, "%d chars in %d line\n", count_of_chars, count_of_lines);
	fclose(Fin);
	fclose(Fout);
	return 0;
}
