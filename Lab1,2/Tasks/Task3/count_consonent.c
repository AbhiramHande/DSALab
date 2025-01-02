#include "count.h"

int count(char* string) {
    int count = 0;
    for (int i = 0; i < strlen(string); i++) {
        char character = tolower(string[i]);
        if (character > 97 && character < 123 && character != 105 && character != 101 && character != 111 && character != 117) {
            count++;
        }
    }
    return count;
}