#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <math.h>


int MinABS(int x, int* arr, int sizearr);

int main(int argc, char** argv) {
	const int sizeA = 10, sizeB = 20;
	int A[sizeA];
	int B[sizeB];
	int C[sizeA];
	srand(_getpid());

	for (int i = 0; i < sizeA; i++) {
		*(A + i) = rand() % 100;
		printf("%d ", *(A + i));
	}
	printf("\n");
	for (int i = 0; i < sizeB; i++) {
		*(B + i) = rand() % 100;
		printf("%d ", *(B + i));
	}
	printf("\n");
	for (int i = 0; i < sizeA; i++) {
		*(C + i) = *(A + i) + *(B + MinABS(*(A + i), B, sizeB));
		printf("%d ", *(C + i));
	}
	return 0;
}

int MinABS(int x, int* arr, int sizearr) {
	int Abs = abs(*arr - x);
	int k = 0;
	for (int i = 0; i < sizearr; i++)
		if (abs(*(arr + i) - x) < Abs) {
			Abs = abs(*(arr + i) - x);
			k = i;
		}
	return k;
}
