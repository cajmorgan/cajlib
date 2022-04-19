#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>


void reverseString(char* string) {
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


int addChar(char* dest, char char_to_add, int size_of_dest) {
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
