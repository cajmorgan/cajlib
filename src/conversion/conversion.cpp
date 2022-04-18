#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <conversion/conversion.h>

/* String to Int */
int stringToInt(char* string, int* dest) {
    int stringLength = strlen(string);
    int convertedNumber = 0;
    int power = 1;

    for (int i = stringLength - 1; i >= 0; i--) {
        convertedNumber += ((string[i] - 48) * power);
        power *= 10;
    }

    *dest = convertedNumber;

    return 0;
}


/* Int to String */
int intToString(int number, char* string) {

}