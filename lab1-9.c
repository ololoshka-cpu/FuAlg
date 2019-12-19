#include <stdio.h>

int main() {
	int n, answ = 0;
	scanf("%d", &n);
	if (n == 0) {
		printf("Enter a nonzero number");
		scanf("%d", &n);
	}
	else {
		for (int i = 1; i <= n; i++) {
			answ += i;
		}
		printf("%d\n", answ);
	}
	return 0;
}
