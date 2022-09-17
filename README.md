# C-Classes
## A library that permits Classes in C
### Note that this does _not_ use C++, not sure why github claims so
```C
#include <stdio.h>
#include "lib.h"

typedef struct
{
    int height;
    int width;

    includes(constructor(Room));

    uses_methods();

} Class(Room);

uint64_t extends(Room, area)(void)
{  
    methodfor(Room);
    return (this->height * this->width);
}

uint64_t extends(Room, volume)(int vertical)
{
    methodfor(Room);
    return (this->height * this->width * vertical);
}


methods_for(Room) = {
    (method_t)extends(Room, area),
    (method_t)extends(Room, volume),
};

#define area 0
#define volume 1

Room_t constructor(Room)(int width, int height)
{
    initiates(Room);
    this.width = width;
    this.height = height;

    return this;
}

asClass(Room, livingRoom);
asClass(Room, bedroom);

int main()
{
    New(Room, livingRoom, 10, 10);
    New(Room, bedroom, 15, 5);
    
    printf("The area of the bedroom is: %i \n", (int) livingRoom.method(area));
    printf("The area of the livingroom is: %i \n", (int) bedroom.method(area));

    printf("The volume of the bedroom is: %i \n", (int) livingRoom.method(volume, 23));
}
```

### Complex:
```C
#include <stdio.h>
#include <string.h>

#include "lib.h"

// Create our class
typedef struct
{
    // Create any properties
    char *contents;
    
    // Include the constructor and specify that you ar eusing methods
    includes(constructor(String));
    uses_methods();
} Class(String);

// All methods must return uint64
uint64_t extends(String, length)(void) 
{
    // Pull data from the class
    methodfor(String);
    
    // "this" is a pointer to the object
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

// You can only pass one argument, so use an array
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

    // Cast to RPOINTER to return a pointer
    return RPOINTER newString;
}

// Attached each function to the class
methods_for(String) = {
    (method_t)extends(String, length),
    (method_t)extends(String, charAt),
    (method_t)extends(String, indexOf),
    (method_t)extends(String, substring)
};

// for easy use
#define length    0 // index 0
#define charAt    1 // index 1
#define indexOf   2 // index 2
#define substring 3 // index 3

// Create the constructor for the class
// Return <class>_t
String_t constructor(String)(char *contents)
{
    initiates(String); // Initialize the object
    this.contents = contents;
    return this; // return the class
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

```
