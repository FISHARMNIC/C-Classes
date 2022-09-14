#include <stdio.h>
#include <string.h>
#include "lib.h"

// Define the structure of the class
typedef struct
{
    // Include any properties 
    char * contents;

    // Define the inclusion of the constructor
    includes(void, constructor(String));

    // Specify that you the class uses methods
    uses_methods();
} Class(String); // Create the class "String"

// Defines the function "length" as an extension of "String"
int extends(String, length)(void)
{
    return strlen(String_this.contents);
}

// Defines the function "charAt" as an extension of "String"
int extends(String, charAt)(int parg)
{
    return String_this.contents[parg];
}

// Specifies the methods used for "String"
// Casts to "method_t" to assert the correct type of function
methods_for(String) = {
    (method_t) extends(String, length),
    (method_t) extends(String, charAt),
};

// Create macros to ease yourself, in accordance with the order of the "methos_for" array
#define length 0
#define charAt 1

// Create the constructor with the parameters you want
String_t constructor(String)(char * contents)
{
    // "this" will be the returned value
    String_t this;

    // Specify that this is the initiator function
    initiates(String);

    // Modify and properties 
    this.contents = contents;

    // Return the value
    return this;
}

// Globally declare the "myString" class as a string
asClass(String, myString);

int main()
{
    // Initiate the class starting with the type, name, and any parameters specified by the constructor
    myString = New(String, myString, "Hello, World!");

    // Call methods with the "execute" property
    printf("The length of \"%s\" is %i \n", myString.contents, myString.execute(length));
    printf("The 1'st character of \"%s\" is %c \n", myString.contents, myString.execute(charAt, 1));
}