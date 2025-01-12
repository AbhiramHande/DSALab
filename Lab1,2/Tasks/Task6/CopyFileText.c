#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file_1 = fopen("text1.txt", "ab");
    FILE *file_2 = fopen("text2.txt", "r");
    char ch;
    while((ch = fgetc(file_2)) != EOF) {
        fputc(ch, file_1);
    }

    fclose(file_1);
    fclose(file_2);

    FILE *file = fopen("text2.txt", "w");
    fclose(file);
}