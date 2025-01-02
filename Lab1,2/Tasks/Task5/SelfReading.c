#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file = fopen(__FILE__, "r");
    char ch;
    while((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
}
