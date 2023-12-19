#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fileIn, *fileOut;
    char ch;

    fileIn = fopen("input.txt", "r");
    if (fileIn == NULL) {
        perror("Error opening file");
        return 1;
    }

    fileOut = fopen("output.txt", "w");
    if (fileOut == NULL) {
        perror("Error opening file");
        fclose(fileIn);
        return 1;
    }

    while ((ch = fgetc(fileIn)) != EOF) {
        if (ch != ' ') {
            fputc(ch, fileOut);
        }
    }

    fclose(fileIn);
    fclose(fileOut);

    printf("File processed successfully.\n");
    return 0;
}
