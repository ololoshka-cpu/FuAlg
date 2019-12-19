#include <stdio.h>

int main() {
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	if (a + b <= c || b + c <= a || c + a <= b)
		printf("These values cannot be the lengths of the sides of the triangle");
	else
		printf("These values can be the lengths of the sides of the triangle");
	return 0;
}
