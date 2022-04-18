#include <string.h>


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
