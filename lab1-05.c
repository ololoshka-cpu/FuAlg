#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	if (a * b == 0)
		printf("Zero numbers are entered\n");
	else
		if (a % b != 0) {
			printf("a is not a multiple of b\n");
		}
		else
			printf("a multiply of b, multiplicity is equal to %d\n", a / b);
	return 0;
}
