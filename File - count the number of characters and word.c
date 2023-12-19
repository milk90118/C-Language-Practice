#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

int main() {
    FILE *file;
    char filename[100];
    char ch;
    int characters = 0, words = 0;
    bool inWord = false;

    // Get the filename from the user
    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file in read mode
    file = fopen(filename, "r");

    // Check if the file exists
    if (file == NULL) {
        printf("File not found or unable to open the specified file.\n");
        return 1;
    }

    // Read the file character by character
    while ((ch = fgetc(file)) != EOF) {
        // Count characters
        characters++;

        // Check if the character is a separator
        if (isspace(ch)) {
            if (inWord) {
                words++;
                inWord = false;
            }
        } else {
            inWord = true;
        }
    }

    // Close the file
    fclose(file);

    // Count the last word if the file doesn't end with a separator
    if (inWord) {
        words++;
    }

    printf("Total characters: %d\n", characters);
    printf("Total words: %d\n", words);

    return 0;
}
