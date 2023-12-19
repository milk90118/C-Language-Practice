#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fileRead, *fileWrite;
    char inputFilename[100], outputFilename[100];
    char buffer[1024];  // Buffer to store file content

    // Get input and output file names
    printf("Enter the input file name: ");
    scanf("%s", inputFilename);
    printf("Enter the output file name: ");
    scanf("%s", outputFilename);

    // Open the input file for reading
    fileRead = fopen(inputFilename, "r");
    if (fileRead == NULL) {
        printf("Failed to open %s for reading.\n", inputFilename);
        return 1;
    }

    // Read contents from file
    if (fgets(buffer, sizeof(buffer), fileRead) == NULL) {
        printf("Error or end of file reached while reading %s.\n", inputFilename);
        fclose(fileRead);
        return 1;
    }

    // Close the input file
    fclose(fileRead);

    // Open the output file for writing
    fileWrite = fopen(outputFilename, "w");
    if (fileWrite == NULL) {
        printf("Failed to open %s for writing.\n", outputFilename);
        return 1;
    }

    // Write to the output file
    fprintf(fileWrite, "%s", buffer);

    // Close the output file
    fclose(fileWrite);

    printf("File content successfully written to %s\n", outputFilename);
    return 0;
}
