#include <stdio.h>

int main() {
	float a, b, c;
	bool answer;
	scanf("%f %f %f", &a, &b, &c);
	if (a >= b && a >= c)
		answer = a * a == b * b + c * c;
	else if (b >= a && b >= c)
		answer = b * b == a * a + c * c;
	else
		answer = c * c == a * a + b * b;
	if (!answer)
		printf("These values cannot be the lengths of the sides of the triangle");
	else
		printf("These values can be the lengths of the sides of the triangle");
	return 0;
