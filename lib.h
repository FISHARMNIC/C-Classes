#include <stdlib.h>

typedef void constructor_t();
typedef int (*method_t)();

#define Class(name)         \
    name##_t;               \
    typedef name##_t *name; \
    name##_t name##_this

#define _exec_fn_(variable) variable##_execute

#define asClass(class, variable)                \
    class##_t variable;                         \
    int variable##_execute(int fn, void *param) \
    {                                           \
        class##_this = variable;                \
        return variable.methods[fn](param);     \
    }

#define constructor(class) class##_cons__
#define extends(class, name) class##_##name
#define includes(returnType, name) returnType (*name)()

#define uses_methods() \
    method_t execute;  \
    int methods_used;  \
    method_t *methods

//#define uses_methods(class, amt, ...) method_t methods_used; method_t *methods;} Class(class); methods_for(class, amt) = {__VA_ARGS__}
#define methods_for(class) method_t class##_methods[]
#define initiates(class)                                                    \
    this.methods = class##_methods;                                         \
    this.methods_used = sizeof class##_methods / sizeof class##_methods[0]; \

#define New(class, name,...) constructor(class)(__VA_ARGS__); name.execute = _exec_fn_(name);

#define init_fn()

// #define class_param(type, name, value) type *name = malloc(sizeof(type)); *name = value
// #define class_param_as(type, name) (*((type *)name))