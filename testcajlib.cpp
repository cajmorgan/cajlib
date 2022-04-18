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

	}

	if (argv <= 2)
		printf("works...");
	return 0;
}