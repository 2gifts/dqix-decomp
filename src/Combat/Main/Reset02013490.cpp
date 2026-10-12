#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void Mat3x3_WriteIdentity(void*);

#if defined(jpn)
#define Reset02013490 func_02013258
extern "C" ARM void Reset02013490(char* obj);
#endif

// USA: func_02013490
ARM void Reset02013490(char* obj) {
    *(int*)(obj + 0) = 0;
    *(int*)(obj + 0x38) = 0;
    *(short*)(obj + 4) = 0;
    memset(obj + 6, 0, 9);
    memset(obj + 0xf, 0, 5);
    Mat3x3_WriteIdentity(obj + 0x14);
    *(int*)(obj + 0x3c) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
}
