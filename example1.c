#include <stdio.h>
#include "lib.h"

typedef struct
{
    int height;
    int width;

    includes(constructor(Room));
    uses_methods();

} Class(Room);

uint64_t method(Room, area)(void)
{
    methodfor(Room);
    return (this->height * this->width);
}

uint64_t method(Room, volume)(int vertical)
{
    methodfor(Room);
    return (this->height * this->width * vertical);
}


methods_for(Room) = {
    (method_t)method(Room, area),
    (method_t)method(Room, volume),
#define area 0
#define volume 1

};


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

    printf("The area of the bedroom is: %i \n", (int)livingRoom.call(area));
    printf("The area of the livingroom is: %i \n", (int)bedroom.call(area));

    printf("The volume of the bedroom is: %i \n", (int)livingRoom.call(volume, 23));
}