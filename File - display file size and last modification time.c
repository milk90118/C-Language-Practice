/* C Program to Display File Size and Last Modification Time
Note: This program works on Unix-like systems, including Linux and macOS.*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    struct stat fileInfo;
    char filename[100];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    if (stat(filename, &fileInfo) != 0) {
        perror("Error getting file info");
        return 1;
    }

    printf("Size of '%s': %ld bytes\n", filename, fileInfo.st_size);

    // Convert the last modified time to readable format
    char modTime[20];
    strftime(modTime, 20, "%Y-%m-%d %H:%M:%S", localtime(&fileInfo.st_mtime));
    printf("Last modified time: %s\n", modTime);

    return 0;
}
