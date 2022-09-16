#include <stdio.h>
#include "lib.h"

typedef struct
{
    int height;
    int width;

    includes(constructor(Room));

    uses_methods();

} Class(Room);

int extends(Room, area)(void)
{  
    methodfor(Room);
    return (this->height * this->width);
}

int extends(Room, volume)(int vertical)
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

// when you intiaite it makes a special function that sets the static variable that all use

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