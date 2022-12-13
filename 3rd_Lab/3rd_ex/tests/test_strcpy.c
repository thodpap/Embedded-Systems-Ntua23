#include <stdio.h>

extern char *strcpy(char *dest, const char *src);

int main(int argc, char *argv[]) 
{
    char dest[100];
    char *test;

    test = strcpy(dest, argv[1]);

    printf("Initial string was %s\nCopy is: %s\ntest: %s\n", argv[1], dest, test);
    return 0;
}