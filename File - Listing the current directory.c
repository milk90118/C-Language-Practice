#include <windows.h>
#include <stdio.h>

int main() {
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = FindFirstFile(".\\*", &findFileData);

    if (hFind == INVALID_HANDLE_VALUE) {
        printf("FindFirstFile failed (%d)\n", GetLastError());
        return 1;
    } 

    do {
        printf("%s\n", findFileData.cFileName);
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
    return 0;
}
