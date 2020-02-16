#include <stdio.h>
#include <stdlib.h>
#define digit (*(string + k)>=48 && *(string + k) <= 57)
#define nodigit !(*(string + flag) >= 48 && *(string + flag) <= 57)
#define letter (*(string + k) >=65 && *(string + k) <=90 || *(string + k) >= 97 && *(string + k) <= 122)
#define noletter !(*(string + flag) >= 65 && *(string + flag) <= 90 || *(string + flag) >= 97 && *(string + flag) <= 122)
void sort(char* string);

int main(int argc, char** argv) {
	char str[] = "ynsdksneufh47oi23u09x   3482398wjsuw72\0";

	sort(str);

	printf(str);
	
	return 0;
}

void sort(char* string) {
	int k = 0;
	int flag = 0;
	while (*(string + k) != '\0') {
		if (digit && nodigit){
			char tmp = *(string + k);
			*(string + k) = *(string + flag);
			*(string + flag) = tmp;
			flag++;
		}
		if (digit)
			flag++;
		k++;
	}
	printf("%s\n", string);
	k = flag;
	while (*(string + k) != '\0') {
		if (letter && noletter){
			char tmp = *(string + k);
			*(string + k) = *(string + flag);
			*(string + flag) = tmp;
			flag++;
		}
		if (letter)
			flag++;
		k++;
	}
}
