# ObjectOrientedC
## A library that permits Classes in C

```C
#include <stdio.h>
#include <string.h>

#include "lib.h"

// Define your new class like so
typedef struct
{
    // Create any properties you want
    char *contents;
    
    // Specify the constructor you are including 
    includes(constructor(String));
    
    // Specify that you are going to be using methods
    uses_methods();
} Class(String); // <-- Name of the class. Creates the <class> and <class_t> types

// Create a method for the Class
// Return a 64 bit number to permit all data types
uint64_t extends(String, length)(void) 
{
    // Use <class>_this to access the object
    // You should cast values before returning them as the 64 bit number
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

// You can only have one parameter in a method, so use an array to pass multiple
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

// These are all the methods that are to included in the class
methods_for(String) = {
    (method_t)extends(String, length),
    (method_t)extends(String, charAt),
    (method_t)extends(String, indexOf),
    (method_t)extends(String, substring)};

// The array of methods ^^^ may be difficult to access. So create macros to ease yourself
#define length 0 // index 0
#define charAt 1 // index 1
#define indexOf 2
#define substring 3

// The constructor function should return <class>_t
String_t constructor(String)(char *contents)
{
    initiates(String);
    
    // Use "this" to set the objects properties
    this.contents = contents;
    return this;
}

// Globally declare your object like so
asClass(String, myString);

int main()
{
    // Initiate the class with the type and name, followed by any parameters specified by the constructor
    // Unlike methods, the constructor can take multiple parameters
    New(String, myString, "Hello, World!");

    printf("The length of \"%s\" is %llu \n", myString.contents, myString.method(length));
    // It's important to cast back from the 64 bit return value to avoid warnings
    printf("The 0'th character of \"%s\" is '%c' \n", myString.contents, (char)myString.method(charAt, 0));

    char *substr = (char *)myString.method(substring, (int[]){7, 12});
    printf("Characters 7-12 are %s \n", substr);
    free(substr);
}

```
