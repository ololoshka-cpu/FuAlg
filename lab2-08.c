# include <stdio.h>

float power(float x, int y);
float powerUp(float x, int y);
float powerDown(float x, int y);

int main(int argc, char** argv) {
	float x;
	int y;
	printf("Enter x and y:");
	if (scanf("%f %d", &x, & y))
		printf("\n%f", power(x, y));
	return 0;
}

float power(float x, int y) {

	if (y < 0)
		return powerDown(x, y);
	else
		return powerUp(x, y);
}

float powerUp(float x, int y) {
	if (y > 0)
		return x * powerUp(x, y - 1);
	else
		return 1;
}

float powerDown(float x, int y) {
	if (y < -1)
		return (float)(powerDown(x, y + 1)/x);
	else
		return (float)(1/x);
}
