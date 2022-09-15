#include <stdio.h>
#include "lib.h"

typedef struct
{
    int height;
    int width;

    includes(void, constructor(Room));

    uses_methods();

} Class(Room);

int extends(Room, area)(void)
{
    return (Room_this.height * Room_this.width);
}

int extends(Room, volume)(int vertical)
{
    return (Room_this.height * Room_this.width * vertical);
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
    livingRoom = New(Room, livingRoom, 10, 10);
    bedroom = New(Room, bedroom, 15, 5);
    printf("The area of the bedroom is: %i \n", livingRoom.execute(area));
    printf("The area of the livingroom is: %i \n", bedroom.execute(area));

    printf("The volume of the bedroom is: %i \n", livingRoom.execute(volume, 23));
}