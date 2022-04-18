#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <conversion/conversion.h>
#include <string/string.h>
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
int intToString(int number, char* dest) {
    int remainder = 0;
    int numberToConvert = number;
    char reversedNumber[16] = { '\0' };
    int counter = 0;

    while (numberToConvert > 0) {
        remainder = numberToConvert % 10;
        reversedNumber[counter] = remainder + 48;
        numberToConvert /= 10;
        counter++;
    }

    reverseString(reversedNumber);
    strcpy(dest, reversedNumber);

    return 0;
}