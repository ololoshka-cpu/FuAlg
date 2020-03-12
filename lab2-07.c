#include <stdio.h>
#include <stdarg.h>
#include <math.h>

void theGeometricMean(int n, ...);

int main(int argc, char** argv) {
	theGeometricMean(3, 2.0, 2.0, 16.0);
	return 0;
}

void theGeometricMean(int n, ...) {
	float answer = 1.0;
	va_list arg;
	va_start(arg, n);
	for (int i = 0; i < n; i++) {
		answer *= va_arg(arg, double);
		//printf("%f\n", answer);
	}
	va_end(arg);

	printf("%f",pow(answer,(double)1/n));
}
