#include <stdio.h>
#include <string.h>

#include "lib.h"

typedef struct
{
    char *contents;
    includes(constructor(String));
    uses_methods();
} Class(String);

uint64_t extends(String, length)(void) 
{
    return (int)strlen(String_this.contents);
}

uint64_t extends(String, charAt)(int index) 
{
    return (char)String_this.contents[index];
}

uint64_t extends(String, indexOf)(char character)
{
    int len = strlen(String_this.contents);
    int index;
    while (index < len)
    {
        if (String_this.contents[index] == character)
            return index;
        index++;
    }
    return -1;
}

uint64_t extends(String, substring)(int args[2])
{
    int start = args[0];
    int end = args[1];

    if (end < start || end > strlen(String_this.contents))
        return 0;

    char *newString = malloc(end - start + 1);

    int j = 0;
    for (int i = start; i < end; i++, j++)
    {
        newString[j] = String_this.contents[i];
    }
    newString[++j] = '\0';

    return (uint64_t)newString;
}

methods_for(String) = {
    (method_t)extends(String, length),
    (method_t)extends(String, charAt),
    (method_t)extends(String, indexOf),
    (method_t)extends(String, substring)};

#define length 0 // index 0
#define charAt 1 // index 1
#define indexOf 2
#define substring 3

String_t constructor(String)(char *contents)
{
    initiates(String);
    this.contents = contents;
    return this;
}

asClass(String, myString);

int main()
{
    New(String, myString, "Hello, World!");

    printf("The length of \"%s\" is %llu \n", myString.contents, myString.execute(length));
    printf("The 0'th character of \"%s\" is '%c' \n", myString.contents, (char)myString.execute(charAt, 0));

    char *substr = (char *)myString.execute(substring, (int[]){7, 12});
    printf("Characters 7-12 are %s \n", substr);
    free(substr);
}
