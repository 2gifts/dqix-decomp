#include <globaldefs.h>
#include "std_library_functions.h"

#if defined(jpn)
extern "C" void func_0206ef94(unsigned char* arr);
#define ResetElementArray0206de40 func_0206ef94
#else
void ResetElementArray0206de40(unsigned char* arr);
#endif

// JPN: func_0206ef0c
// USA: func_0206ddb8  (semantic: ResetBigStruct0206ddb8)
extern "C" ARM void func_0206ddb8(unsigned char* obj) {
    obj[0x332] = 0;
    memset(obj + 0x8c, 0, 0x234);
    memset(obj + 0x2c0, 0, 0xc);
    ResetElementArray0206de40(obj);
    memset(obj + 0x2cc, 0, 0x66);
    memset(obj + 0x334, 0, 0xce);
    *(int*)(obj + 0x404) = 0;
    *(int*)(obj + 0x408) = 0;
    memset(obj + 0x40c, 0, 0xf);
    memset(obj + 0x41b, 0, 0x40);
}
