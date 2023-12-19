#include <stdio.h>
#include <string.h>

int main() {
    char str[100], replaceChar;
    printf("Input a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0; // Remove newline character from input

    printf("Input replace character: ");
    scanf("%c", &replaceChar);

    for(int i = 0; str[i] != '\0'; ++i) {
        if(str[i] == ' ') {
            str[i] = replaceChar;
        }
    }

    printf("After replacing the space with %c the new string is:\n%s\n", replaceChar, str);
    return 0;
}
