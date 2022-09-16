#include <stdlib.h>
#include <stdint.h>

typedef void constructor_t();
typedef uint64_t (*method_t)();

void * _glob_this = NULL;

#define Class(name)         \
    name##_t;               \
    typedef name##_t *name \


#define _exec_fn_(variable) variable##_method

#define asClass(class, variable)                \
    class##_t variable;                         \
    uint64_t variable##_method(int fn, void *param) \
    {                                           \
        _glob_this = (void*) &variable;                \
        uint64_t rtnV = variable.methods[fn](param); \
        variable = * (class)_glob_this; \
        return rtnV; \
    }

#define methodfor(class) class this = (class)_glob_this;
#define constructor(class) class##_cons__
#define extends(class, name) class##_##name
#define includes(name) uint64_t (*name)()

#define uses_methods() \
    method_t method;  \
    int methods_used;  \
    method_t *methods

#define methods_for(class) method_t class##_methods[]
#define initiates(class)                                                    \
    class##_t this; \
    this.methods = class##_methods;                                         \
    this.methods_used = sizeof class##_methods / sizeof class##_methods[0] \

#define New(class, name,...) name = constructor(class)(__VA_ARGS__); name.method = _exec_fn_(name)

#define init_fn()

#define RPOINTER (uintptr_t)
#define RVALUE (uint64_t)