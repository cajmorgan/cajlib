#include <stdio.h>
#include <stdlib.h>
#include <cajlib.h>
#include <string.h>



int main(int argv, char *argc[]) {
	
	if (argv > 2) {
		if (strcmp("stringToInt", argc[1]) == 0) {
			int dest = 0;
			stringToInt(argc[2], &dest);
			printf("result: %d", dest);
		}
		else if (strcmp("intToString", argc[1]) == 0) {
			char dest[16] = { '\0' };
			int number = 0;
			stringToInt(argc[2], &number);
			intToString(number, dest);

			printf("result: %s", dest);
		}
		else if (strcmp("addChar", argc[1]) == 0) {
			char dest[16] = { '\0' };
			strcpy(dest, argc[2]);
			addChar(dest, 'l', 16);
			addChar(dest, 'o', 16);
			printf("result: %s", dest);
		}
		else if (strcmp("decimalToBinary", argc[1]) == 0) {
			char bytes[50] = { '\0' };
			int dest = 0;
			stringToInt(argc[2], &dest);
			decimalToBinary(dest, bytes);
			printf("result: %s", bytes);
		}

	}

	if (argv <= 2)
		printf("works...");
	return 0;
}