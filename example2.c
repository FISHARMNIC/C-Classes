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
    methodfor(String);
    return (int)strlen(this->contents);
}

uint64_t extends(String, charAt)(int index) 
{
    methodfor(String);
    return (char)this->contents[index];
}

uint64_t extends(String, indexOf)(char character)
{
    methodfor(String);
    int len = strlen(this->contents);
    int index;
    while (index < len)
    {
        if (this->contents[index] == character)
            return index;
        index++;
    }
    return -1;
}

uint64_t extends(String, substring)(int args[2])
{
    methodfor(String);
    int start = args[0];
    int end = args[1];

    if (end < start || end > strlen(this->contents))
        return 0;

    char *newString = malloc(end - start + 1);

    int j = 0;
    for (int i = start; i < end; i++, j++)
    {
        newString[j] = this->contents[i];
    }
    newString[++j] = '\0';

    return RPOINTER newString;
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

    printf("The length of \"%s\" is %llu \n", myString.contents, myString.method(length));
    printf("The 0'th character of \"%s\" is '%c' \n", myString.contents, (char)myString.method(charAt, 0));

    char *substr = (char *)myString.method(substring, (int[]){7, 12});
    printf("Characters 7-12 are %s \n", substr);
    free(substr);
}
