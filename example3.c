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
    int* oldAddr = Int_Array_this.arr;
    int* newAddr = malloc(Int_Array_this.length * sizeof(int) + 1);
    memcpy(newAddr, oldAddr, (Int_Array_this.length) * sizeof(int) + 1);
    free(oldAddr);
    newAddr[++Int_Array_this.length] = value;
    Int_Array_this.arr = newAddr;
    return RPOINTER newAddr;
}

uint64_t extends(Int_Array, pop)(void)
{
    int* oldAddr = Int_Array_this.arr;
    int* newAddr = malloc(Int_Array_this.length * sizeof(int) - 1);
    memcpy(newAddr, oldAddr, (Int_Array_this.length) * sizeof(int) - 1);
    int ret = oldAddr[Int_Array_this.length--];
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

    myArr.execute(push, 4);

    printf("----\n");
    for(i = 0; i <= myArr.length; i++)
        printf("- %i\n", myArr.arr[i]);
    
    myArr.execute(pop);

    printf("----\n");
    for(i = 0; i <= myArr.length; i++)
        printf("- %i\n", myArr.arr[i]);


}