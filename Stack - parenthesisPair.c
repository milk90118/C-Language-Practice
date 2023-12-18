/*Problem: Design a program, which can read a string from the keyboard 
and determine whether the parentheses in the string are paired.

Constraints: This can be done using recursion, but other methods are allowed.
The string is no more than 30 characters, and contains alphabets in both upper and
lower cases, numbers, +, -, *, /, (, )
The ASCII code of ( and ) are 40 and 41 in 10-based, respectively
Example: (a+b33/*) True */

#include <stdio.h>
#include <stdbool.h>

bool parenthesePaired(const char* str)
{
    int stack[30];
    int top = -1;

    for(int i = 0; str[i] != '\0'; ++i)
    {
        if(str[i] == '(')
        {
            // Push index of '(' onto stack
            top++;
            stack[top] = i;
        }

        else if(str[i] == ')')
        {
            // If stack is empty or top element is not '(', return false
            if(top == -1) return false;

            // Pop the top element from stack
            top--;
        }
    }

    // If stack is empty, all parentheses are paired
    return top == -1;
}

int main()
{
    char string[31];

    scanf("%30s", string);
    
    if(parenthesePaired(string))
    {
        printf("True\n");
    }
    else printf("False\n");

    return 0;
}