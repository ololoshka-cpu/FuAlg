#include <stdio.h>

int main() {
	int a,b;
	b = 0;
	scanf("%d", &a);
	if (a > 999999 && a < 10000000) {
		while (a > 0) {
			b = b * 10 + a % 10;
			a = a / 10;
		}
		while (b > 0) {
			printf("%d ", b % 10);
			b = b / 10;
		}
	}
	else
		printf("It's not 7-digits number\n");
	return 0;
}
