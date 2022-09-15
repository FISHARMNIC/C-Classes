#include <stdio.h>
#include <string.h>
#include "lib.h"

// Define the structure of the class
typedef struct
{
    // Include any properties here
    char *contents;

    // Define the inclusion of the constructor
    includes(void, constructor(String));

    // Specify that the class uses methods
    uses_methods();

} Class(String); // Create the class "String"

// Defines the function "length" as a method belonging to "String"
int extends(String, length)(void)
{
    //use <type>_this to read the contents of the structure
    return strlen(String_this.contents);
}

// Defines the function "charAt" as a method belonging to "String"
int extends(String, charAt)(int index)
{
    return String_this.contents[index];
}

// Specify the methods to use for "String"
methods_for(String) = {
    (method_t) extends(String, length),
    (method_t) extends(String, charAt),
};

// "methods_for" is stores as a list with the method id. Create macros to ease yourself
#define length 0 // index 0
#define charAt 1 // index 1

// Create the constructor for the class with the parameters you want
// Note you need to return <classname>_t
String_t constructor(String)(char *contents)
{
    // Specify that this is the initiator/constructor function
    initiates(String);

    // Modify the properties using "this"
    this.contents = contents;

    // Return "this" to initialize the object
    return this;
}

// Globally declare the your class
asClass(String, myString);

int main()
{
    // Initiate the class starting with the type and name, followed by any parameters specified by the constructor
    New(String, myString, "Hello, World!");

    // Call methods with the "execute" property
    // Pass the function name or identification number
    printf("The length of \"%s\" is %i \n", myString.contents, myString.execute(length));
    printf("The 0'th character of \"%s\" is '%c' \n", myString.contents, myString.execute(charAt, 0));
}