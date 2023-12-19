/* A set of strings represent directory paths and a single directory separater(/)
Task: to get a part of the directory tree that is common to all directories.*/

#include <stdio.h>

int commonPath(const char* const* names, int n, char sep)
{
    for(int pos = 0;; pos++)
    {
        for(int i = 0; i < n; ++i)
        {
            if(names[i][pos] != '\0'
                &&(names[i][pos] == names[0][pos])) continue;

            while(pos > 0 && names[0][--pos] != sep);

            return pos;
        }
    }
    return 0;
}

int main()
{
	const char *names[] = {
		"/home/me/user/temp/a",
		"/home/me/user/temp/b",
		"/home/me/user/temp/c/d",
	};
	int len = commonPath(names, sizeof(names) / sizeof(const char*), '/');
	if (!len) 
	   printf("No common path\n");
	else 
	  printf("Common path: %.*s\n", len, names[0]);

	return 0;
}