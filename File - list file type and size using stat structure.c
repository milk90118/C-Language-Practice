#include <stdio.h>
#include <sys/stat.h>

int main() {
    char filePath[260];
    scanf("%s", filePath);

    struct stat fileInfo;
    if (stat(filePath, &fileInfo) != 0) {
        perror("Error getting file info");
        return 1;
    }

    printf("%s\n", filePath);

    if (S_ISDIR(fileInfo.st_mode)) 
    {
        printf("Type: directory\n");
    } 
    
    else if (S_ISREG(fileInfo.st_mode)) 
    {
        printf("Type: normal file\n");
    }

    long sizeInBytes = fileInfo.st_size;
    
    long sizeInMB = sizeInBytes / (1024 * 1024);

    if (sizeInBytes > 1024 * 1024 * 1024) 
    {
        printf("Size: %ld GB\n", sizeInMB / 1024);
    } 
    else if (sizeInMB >= 1) 
    {
        printf("Size: %ld MB\n", sizeInMB);
    } 
    else {
        printf("Size: %ld bytes\n", sizeInBytes);
    }

    return 0;
}
