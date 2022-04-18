﻿#include <cajlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

/**************\
*STRING METHODS*
\**************/


/* String to Int */
int stringToInt(char *string, int* dest) {
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



int string_copy(char* dest, int size_of_dest, char* src, int size_of_src) {
    if (size_of_dest < size_of_src) {
        errno = 1;
        perror("Size of dest sting needs to be bigger or equal to size of src strirng");
        return 1;
    }

    //Null string
    for (int i = 0; i < size_of_dest; i++) {
        dest[i] = '\0';
    }

    int position = 0;
    while (src[position] != '\0') {
        dest[position] = src[position];
        position++;
    }

    dest[position] = '\0';

    return 0;
}


char* string_concat(char* string_one, char* string_two) {
    /*int total_length = strlen(string_one) + strlen(string_two);
    char* new_string = (char *)calloc(total_length, sizeof(char));
    string_copy(new_string, total_length + 1, string_one, strlen(string_one) + 1);

    int main_position = (strlen(string_one));
    int string_two_position = 0;
    while (string_two[string_two_position] != '\0') {
        new_string[main_position] = string_two[string_two_position];
        main_position++;
        string_two_position++;
    }

    new_string[main_position] = '\0';

    return new_string;*/
    char a = 'a';
    return &a;
}

int add_char(char* dest, char char_to_add, int size_of_dest) {
    int dest_length = strlen(dest);
    if (dest_length + 1 >= size_of_dest) {
        errno = 1;
        perror("The size of the string needs to be at least one more than the length");
        return 1;
    }

    dest[dest_length] = char_to_add;
    dest[dest_length + 1] = '\0';

    return 0;
}

int str_is_identical(char* string_one, char* string_two) {
    int length_of_string_one = strlen(string_one);
    int length_of_string_two = strlen(string_two);
    int is_identical = 0;

    for (int pos = 0; pos < length_of_string_one; pos++) {
        if (string_one[pos] == string_two[pos]) {
            is_identical += 1;
        }
    }

    if (is_identical == length_of_string_one && is_identical == length_of_string_two) {
        return 0;
    }

    return 1;
}

void reverse_string(char string[]) {
    char temp;
    int string_max_index, index, last_index;
    string_max_index = index = last_index = 0;

    while (string[string_max_index] != '\0') {
        string_max_index++;
    }

    string_max_index--;
    last_index = string_max_index;

    while (index <= last_index) {
        temp = string[index];
        string[index] = string[last_index];
        string[last_index] = temp;
        index++;
        last_index--;
    }
}

/******\
 *
 *
 *
 */

void printBinary(unsigned decimal) {
    const int NUMBER_BYTES = 50;
    char bytes[NUMBER_BYTES] = { '\0' };
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

    reverse_string(bytes);
    printf("%s", bytes);
}