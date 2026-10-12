#include <globaldefs.h>

extern "C" void* func_020e52a0(void* arr, int key);

#if defined(jpn)
struct Container020e0310;
int LookupFieldByKey020e0440(struct Container020e0310*, int);
extern "C" char* strcpy(char*, const char*);
// USA: func_020e5294
extern "C" ARM char* func_020e207c(void* arr, char* destination, int key) {
    if (destination == NULL) return NULL;
    const char* name = (const char*)LookupFieldByKey020e0440((Container020e0310*)arr, key);
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
