#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int k = 1;
	char error[] = "No multiples found";
	char error1[] = "Too many arguments";
	if (argc != 2) {
		printf("%s/n", error1);
		return 0;
	}
	if (atoi(argv[1]) == 0) {
		printf("%s\n", error);
		return 0;
	}
	while (k * atoi(argv[1]) <= 100) {
		printf("%d\n", k * atoi(argv[1]));
		k++;
	}
	if (k == 1)
		printf("%s\n", error);

	return 0;
}
