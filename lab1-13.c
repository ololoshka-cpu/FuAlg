#include <stdio.h>
#include <stdlib.h>
#define Symbol (c != ' ' && c != '\n')

char *NewMemory(char* arr, int SIZE) {
	char* arr1 = (char*)calloc(SIZE + 50,sizeof(char));
	for (int i = 0; i < SIZE; i++)
		*(arr1+i) = *(arr + i);
	free(arr);
	return arr1;
}

int main(int argc, char** argv) {
	int SIZE = 50, i = 0, k = 0, flag1 = 1, flag2;
	char *str = (char*)calloc(SIZE,sizeof(char));
	char c;
	int border[] = { -1,-1,-1,-1 };

	FILE* fin, * fout;

	fin = fopen(argv[1], "r");
	fout = fopen("C:/Users/Andrew's PC/source/repos/ConsoleApplication1/Debug/answer.txt", "w");

	while ((c = fgetc(fin)) != EOF) {
		if (c != '\n') {
			str[i] = c;
			if (Symbol)
				flag2 = 1;
			else
				flag2 = 0;
			if (flag1 != flag2) {
				if (flag2 == 0) {
					border[k] = i;
					flag1 = 0;
				}
				else {
					border[k] = i;
					flag1 = 1;
				}
				k++;
			}
			i++;
			if (i == SIZE) {
				str = NewMemory(str, SIZE);
				SIZE += 50;
			}
		}
		else {
			if (border[2] + border[3] == -2) {
				fprintf(fout," ");
				for (int q = 0; q < i; q++)
					fprintf(fout,"%c", *(str + q));
			}
			else if (border[3] == -1) {
				fprintf(fout," ");
				for (int q = 0; q < border[2]; q++)
					fprintf(fout,"%c", *(str + q));
			}
			else {
				for (int q = border[3]; q < i; q++)
					fprintf(fout,"%c", *(str + q));
				for (int q = border[2]; q < border[3]; q++)
					fprintf(fout,"%c", *(str + q));
				for (int q = 0; q < border[3]; q++)
					fprintf(fout,"%c", *(str + q));
			}
			i = 0;
			k = 0;
			flag1 = 1;
			free(str);
			SIZE = 50;
			str = (char*)calloc(SIZE, sizeof(char));
			border[0] = border[1] = border[2] = border[3] = -1;
			fprintf(fout,"\n");

		}		
	}
	if (i != 0) {
		if (border[0] + border[1] + border[2] + border[3] == -4 || border[2] + border[3] == -2) {
			fprintf(fout," ");
			for (int q = 0; q < i; q++)
				fprintf(fout,"%c", *(str + q));
		}
		else if (border[3] == -1) {
			fprintf(fout," ");
			for (int q = 0; q < border[2]; q++)
				fprintf(fout,"%c", *(str + q));
		}
		else {
			for (int q = border[3]; q < i; q++)
				fprintf(fout,"%c", *(str + q));
			for (int q = border[2]; q < border[3]; q++)
				fprintf(fout,"%c", *(str + q));
			for (int q = 0; q < border[3]; q++)
				fprintf(fout,"%c", *(str + q));
		}
	}
	free(str);
	fclose(fin);
	fclose(fout);
	return 0;
}
