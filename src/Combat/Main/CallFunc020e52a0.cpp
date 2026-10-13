#include <globaldefs.h>

extern "C" void* func_020e52a0(void* arr, int key);

#if defined(jpn)
#include "std_library_functions.h"

struct Container020e0310;


int LookupFieldByKey020e0440(Container020e0310* names, int nameId);
// USA: func_020e5294
extern "C" ARM char* func_020e207c(Container020e0310* names, char* destination, int nameId) {
    if (destination == NULL) return NULL;
    const char* name = reinterpret_cast<const char*>(LookupFieldByKey020e0440(names, nameId));
    if (name == NULL) {
        destination[0] = 0;
        return NULL;
    }
    strcpy(destination, name);
    return destination;
}
#else
// USA: func_020e5294
ARM void* CallFunc020e52a0(void* arr, int key) {
    return func_020e52a0(arr, key);
}
#endif
