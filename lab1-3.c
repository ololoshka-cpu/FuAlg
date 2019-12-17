#include <stdio.h>


int main() {
	FILE * Fin, * Fout;
	char c;
	Fin = fopen("C:/Users/User/Documents/text1.txt", "r");
	Fout = fopen("C:/Users/User/Documents/text2.txt", "w");
	c = fgetc(Fin);
	while (c != EOF) {
		if (c < '0' || c > '9') 
			fputc(c, Fout);
		c = fgetc(Fin);
	}
	fclose(Fin);
	fclose(Fout);
	Fin = fopen("C:/Users/User/Documents/text2.txt", "r");
	Fout = fopen("C:/Users/User/Documents/text1.txt", "w");
	c = fgetc(Fin);
	while (c != EOF) {
		fputc(c, Fout);
		c = fgetc(Fin);
	}
	fclose(Fin);
	fclose(Fout);
	remove("C:/Users/User/Documents/text2.txt");
	return 0;
}
