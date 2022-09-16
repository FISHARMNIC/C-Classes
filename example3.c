#include <stdio.h>
#include <strings.h>

#include "lib.h"

typedef struct
{
    int *arr;
    int length;

    includes(constructor(Int_Array));
    uses_methods();
} Class(Int_Array);

uint64_t extends(Int_Array, push)(int value)
{
    methodfor(Int_Array);

    int* oldAddr = this->arr;
    int* newAddr = malloc(this->length * sizeof(int) + 1);
    memcpy(newAddr, oldAddr, (this->length) * sizeof(int) + 1);
    free(oldAddr);
    newAddr[++this->length] = value;
    this->arr = newAddr;
    return RPOINTER newAddr;
}

uint64_t extends(Int_Array, pop)(void)
{
    methodfor(Int_Array);

    int* oldAddr = this->arr;
    int* newAddr = malloc(this->length * sizeof(int) - 1);
    memcpy(newAddr, oldAddr, (this->length) * sizeof(int) - 1);
    int ret = oldAddr[this->length--];
    free(oldAddr);
    return RVALUE ret;
}

methods_for(Int_Array) = {
    (method_t)extends(Int_Array, push),
    (method_t)extends(Int_Array, pop),
};

#define push 0
#define pop 1

Int_Array_t constructor(Int_Array)(int *init)
{
    initiates(Int_Array);
    this.length = sizeof (int*) / sizeof init[0];
    this.arr = memcpy(malloc(sizeof(int) * this.length + 1), init, sizeof(int) * this.length + 1);
    return this;
}

asClass(Int_Array, myArr);

int main()
{
    New(Int_Array, myArr, (int[]){1,2,3});
    
    int i;
    for(i = 0; i <= myArr.length; i++)
        printf("- %i\n", myArr.arr[i]);

    myArr.method(push, 4);

    printf("----\n");
    for(i = 0; i <= myArr.length; i++)
        printf("- %i\n", myArr.arr[i]);
    
    myArr.method(pop);

    printf("----\n");
    for(i = 0; i <= myArr.length; i++)
        printf("- %i\n", myArr.arr[i]);


}