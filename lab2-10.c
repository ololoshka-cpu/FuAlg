#include <stdio.h>

int chr(char c);
int str(char c);

int main(int argc, char** argv) {
	FILE* fin, *fout;
	fin = fopen("file.TXT", "r");
	fout = fopen("answer.TXT", "w");
	int k = 0, l = 1;
	char c = fgetc(fin);

	while (c != EOF) {
		if (chr(c))
			k++;
		else if (str(c)) {
			fprintf(fout, "%d symbols in %d line\n", k, l);
			l++;
			k = 0;
		}
	}
	fclose(fin);
	fclose(fout);	
}


int chr(char c) {
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return 1;
	return 0;
}

int str(char c) {
	if (c == '\n')
		return 1;
	return 0;
}
