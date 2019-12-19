#include <stdio.h>

int main() {
	int n, answ = 1;
	scanf("%d", &n);
	if (n <= 0)
		if (n == 0)
			printf("1");
		else
			printf("Error: n < 0");
	else {
		for (int i = 1; i <= n; i++)
			answ *= i;
		printf("%d\n", answ);
	}
	return 0;
}
