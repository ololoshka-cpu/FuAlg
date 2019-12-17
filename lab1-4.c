#include <stdio.h>
#include <math.h>

int main() {
	float a, b, c, D;
	scanf("%f %f %f", &a, &b, &c);
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				printf("Infinite number of solutions\n");
			else
				printf("No solution\n");
		}
		else
			if (c == 0)
				printf("%d\n", 0);
			else
				printf("%f\n", (float)-1 * (c / b));
	}
	else
		if (b == 0)
			if (c > 0)
				printf("No solution\n");
			else
				if (c == 0)
					printf("%d\n", 0);
				else
					printf("-%f, %f\n", sqrt(-1 * c), sqrt(-1 * c));
		else
			if (c == 0)
				printf("%f, %f\n", 0.0, -1 * b);
			else {
				D = b * b - 4 * a * c;
				if (D < 0)
					printf("No solution\n");
				else
					if (D == 0)
						printf("%f\n", (float)-1 * b / 2 / a);
					else
						printf("%f, %f\n", (float)(-1 * b - sqrt(D)) / 2 / a, (float)(-1 * b + sqrt(D)) / 2 / a);
			}

	return 0;
}
