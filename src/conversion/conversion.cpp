#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>
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

void decimalToBinary(unsigned decimal, char* bytes) {
    const int NUMBER_BYTES = 50;
    //char bytes[NUMBER_BYTES] = { '\0' };
    int spaceCounter = 1;

    for (int i = 0; i < NUMBER_BYTES; i++) {
        bytes[i] = '0';
        int remainder = 0;
        if (spaceCounter % 5 == 0) {
            bytes[i] = ' ';
            spaceCounter = 1;
            continue;
        }

        remainder = decimal % 2;
        decimal = floor(decimal / 2);
        if (remainder == 1) {
            bytes[i] = '1';
        }

        spaceCounter++;
    }

    char remainder = '0';
    for (int i = NUMBER_BYTES; i >= 0; i--) {
        if (remainder == '1')
            break;

        if (i % 5 == 0) {
            bytes[i - 1] = '\0';
            continue;
        }

        remainder = bytes[i - 1];
    }

    reverseString(bytes);
}