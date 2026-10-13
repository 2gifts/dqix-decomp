#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
#define data_020ef6bc data_020ef59f
#endif
extern char data_020ef6bc;

extern "C" {
    int func_020420e8(char*, int);
}

// KEEP-NAME
// USA: func_02026428
ARM void CopyStringOrDefault02026428(void* obj, const char* name) {
    if (name == NULL)
        strcpy((char*)obj + 0x5b4, &data_020ef6bc);
    else
        strcpy((char*)obj + 0x5b4, name);
#if !defined(jpn)
    *(int*)((char*)obj + 0xbe4) = func_020420e8((char*)obj + 0x5b4, 0);
#endif
}
