#include <stdio.h>
#include <stdlib.h>

int length(char* string);

int main(int argc, char** argv) {
	char str[] = "ynsdksneufh47oi23u09x   3482398wjsuw72\0";

	int len;

	len = length(str);

	printf("Length = %d", len);

	return 0;
}

int length(char* string){
	int k = 0;
	while (*(string + k) != '\0')
		k++;
	return k;
}
