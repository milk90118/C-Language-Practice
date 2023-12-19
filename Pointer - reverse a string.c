/* C program to Reverse a String Using Pointer */

#include <stdio.h>
#include <string.h>

void reverseString(char* str)
{
    int len = strlen(str);

    char *end = str + len - 1; // Pointer to the end of the string

    printf("Reverse String: ");

    while(end >= str) // Iterates backward from the end to the start of the string
    {
        printf("%c", *end);
        end--;
    }
    printf("\n");
}

int main()
{
    char str[100];

    printf("Enter a string: ");

    fgets(str, sizeof(str), stdin);

    // Remove newline character
    size_t len = strlen(str);

    if(len > 0 && str[len - 1] == '\n')
    {
        str[len - 1] = '\0';
    }

    reverseString(str);

    return 0;
}