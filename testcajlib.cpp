#include <cajlib.h>

int main() {
	int dest = 0;
	char string[] = "192";
	stringToInt(string, &dest);
	printf("%d", dest);


	return 1;
}