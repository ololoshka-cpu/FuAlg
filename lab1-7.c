#include <stdio.h>
#include <math.h>

int main() {
	int a;
	scanf("%d", &a);
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j <= a; j++) {
			printf("%d ", (int)pow(i, j));
		}
		printf("\n");
	}
	return 0;
}
