#include <stdio.h>
#include <stdlib.h>
#include <process.h>


int main(int argc, char** argv) {
	const int SIZE = 10;
	int arr[SIZE];
	srand(_getpid());
	for (int i = 0; i < SIZE; i++) {
		arr[i] = rand();
		printf("%d ", arr[i]);
	}
	printf("\n");
	int Min = arr[0];
	int Max = arr[0];
	int Imax;
	int Imin;
	for (int i = 0; i < SIZE; i++) {
		if (*(arr + i) > Max) {
			Max = *(arr + i);
			Imax = i;
		}
		if (*(arr + i) < Min) {
			Min = *(arr + i);
			Imin = i;
		}
	}
	int tmp = *(arr + Imin);
	*(arr + Imin) = *(arr + Imax);
	*(arr + Imax) = tmp;

	for (int i = 0; i < SIZE; i++)
		printf("%d ", *(arr + i));

	return 0;
}
