#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file, *tempFile;
    char filename[100];
    char buffer[1024];
    int lineToReplace;
    char newText[1024];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    // Open the file for reading and a temporary file for writing
    file = fopen(filename, "r");
    tempFile = fopen("temp.txt", "w");

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    printf("Enter the line number to be replaced: ");
    scanf("%d", &lineToReplace);

    printf("Enter the new text: ");
    scanf(" %[^\n]", newText);

    int currentLine = 1;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (currentLine == lineToReplace) {
            fprintf(tempFile, "%s\n", newText);
        } else {
            fprintf(tempFile, "%s", buffer);
        }
        currentLine++;
    }

    // Close the files
    fclose(file);
    fclose(tempFile);

    // Replace the original file with the temporary file
    remove(filename);
    rename("temp.txt", filename);

    printf("Line %d has been replaced with '%s' in '%s'.\n", lineToReplace, newText, filename);

    return 0;
}
