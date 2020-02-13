#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define digit (c>=48 && c<=57 || c>=65 && c<=90 || c>=97 && c<=122)

char* NewMemory(char* number, int SIZE);
char* GetNumber();
bool Stop(char* number);
char* Max(char* max,char* number);
void capitalase(char* number);
int NumberTo10(char* number,int n);
void NumberToN(int number, int n);


int main(int argc, char** argv) {
	int flag = 1;
	char* MAX = nullptr;
	char* number = nullptr;
	int n;
	int answer = 0;

	printf("enter number system: ");
	while(!scanf("%d", &n))
		printf("enter correct number system: ");

	MAX = GetNumber();
	if (Stop(MAX)) {
		flag = 0;
		return 0;
	}
	capitalase(MAX);

	while (flag) {
		number = GetNumber();
		if (Stop(number))
			break;
		capitalase(number);
		MAX = Max(MAX, number);
	}

	answer = NumberTo10(MAX,n);

	printf("MAX in 9-ns:");
	NumberToN(answer, 9);
	printf("MAX in 18-ns:");
	NumberToN(answer, 18);
	printf("MAX in 27-ns:");
	NumberToN(answer, 27);
	printf("MAX in 36-ns:");
	NumberToN(answer, 36);


	return 0;
}
char* GetNumber() {
	char c;
	c = getchar();
	while (!digit) 
		c = getchar();

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
		c = getchar();
	}
	*(number + k) = ' ';
	return number;
}

char* NewMemory(char* number, int SIZE) {
	char* newnumber = (char*)calloc(SIZE + 20, sizeof(char));
	for (int i = 0; i < SIZE; i++)
		*(newnumber + i) = *(number + i);
	free(number);
	return newnumber;
}

bool Stop(char* number) {
	char Stop[4]= { 'S','t','o','p' };
	int i = 0;
	for (i; i < 4; i++)
		if (*(number + i) != Stop[i])
			return false;
	if (*(number + i) == ' ')
		return true;
	return false;
}

void capitalase(char* number) {
	int k = 0;
	while (*(number + k) != ' ') {
		if (*(number + k) >= 97)
			*(number + k) = *(number + k) - 32;
		k++;
	}
}

char* Max(char* max,char* number) {
	int len1 = 0;
	int len2 = 0;
	while (*(max + len1) != ' ' || *(number + len2) != ' ') {
		if (*(max + len1) != ' ')
			len1++;
		if (*(number + len2) != ' ')
			len2++;
	}
	if (len1 != len2) {
		len1 > len2 ? free(number) : free(max);
		return len1 > len2 ? max : number;
	}
	else
		for (int i = 0; i < len1; i++) {
			if (*(max + i) > * (number + i)) {
				free(number);
				return max;
			}
			else if (*(max + i) < *(number + i)) {
				free(max);
				return number;
			}
		}
	free(number);
	return max;
}

int NumberTo10(char* number, int n) {
	int count = 0;
	int answer = 0;
	while (*(number + count) != ' ')
		count++;
	for (int i = 0; i < count; i++) {
		if (*(number + i) >= 65)
			answer += (*(number + i) - 54) * (int)pow((double)n, (double)(count - i - 1));
		else
			answer += (*(number + i) - 48) * (int)pow((double)n, (double)(count - i - 1));
	}
	free(number);
	return answer;
}

void NumberToN(int number, int n) {
	int SIZE = 20;
	int k = 0;
	int ost;
	char* answer = nullptr;
	while (answer == nullptr)
		answer = (char*)calloc(SIZE, sizeof(char));
	while (number) {
		ost = number % n;

		if (ost <= 9)
			*(answer + k) = ost + 48;
		else
			*(answer + k) = ost + 55;
		number = number / n;
		if (SIZE == k + 1) {
			answer = NewMemory(answer, SIZE);
			SIZE += 20;
		}
		k++;
	}
	*(answer + k) = '\0';
	
	for (int i = k-1; i >= 0; i--)
		printf("%c", *(answer + i));
	printf("\n");
}
