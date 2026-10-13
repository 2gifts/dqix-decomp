#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_02042764(const char*, char*, int);
extern char data_020ef6ca;

// KEEP-NAME
// USA: func_020264e4
// JPN: func_02025e64
ARM void SetString020264e4(char* obj, char* name) {
#if defined(jpn)
    if (name != NULL && *name != 0) {
        strcpy(obj + 0x688, name);
    } else {
        strcpy(obj + 0x688, &data_020ef6ca);
    }
#else
    if (name != NULL && *name != 0) {
        func_02042764(name, obj + 0x6f4, 1);
    } else {
        strcpy(obj + 0x6f4, &data_020ef6ca);
    }
#endif
}
