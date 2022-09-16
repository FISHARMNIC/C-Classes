#include <stdio.h>
#include "lib.h"

/*
polymorphism example
*/

typedef struct
{
    char *color;
    int cost;

    includes(constructor(Car));
    uses_methods();
} Class(Car);

typedef struct
{
    extends(Car);

    int topSpeed;
    includes(constructor(SuperCar));
    uses_methods();

} Class(SuperCar);

methods_for(Car) = {};
methods_for(SuperCar) = {};

Car_t constructor(Car)(char * color, int cost)
{
    initiates(Car);
    this.color = color;
    this.cost = cost;
    return this;
}

SuperCar_t constructor(SuperCar)(char * color, int cost, int topSpeed)
{
    initiates(SuperCar);
    super(Car, color, cost);
    this.topSpeed = topSpeed;
    return this;
}

asClass(SuperCar, myCar);

int main()
{
    New(SuperCar, myCar, "red", 100000, 200);
    printf("%s\n", myCar.parent->color);
}