#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	char c;
	FILE* fin, * fout;
	fin = fopen(argv[1], "r");
	fout = fopen("answer.txt", "w");
	while ((c = fgetc(fin)) != EOF) {
		if (c < '0' || c > '9')
			fprintf(fout,"%d", c);
		else
			fprintf(fout,"%c", c);
	}
	fclose(fin);
	fclose(fout);
	fin = fopen("answer.txt","r");
	fout = fopen(argv[1], "w");
	while ((c = fgetc(fin)) != EOF)
		fprintf(fout,"%c", c);
	fclose(fin);
	fclose(fout);
	remove("answer.txt");
	return 0;
}

