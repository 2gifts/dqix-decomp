#include <globaldefs.h>

#if defined(jpn)
enum { kClearSize = 0xb, kHalfOffset = 0xc, kSignedByteOffset = 0xe, kFlagOffset = 0xf };
#else
enum { kClearSize = 0x30, kHalfOffset = 0x30, kSignedByteOffset = 0x32, kFlagOffset = 0x33 };
#endif

#include "std_library_functions.h"

#if defined(jpn)
#define ClearRegion02093980 func_020942ac
extern "C" ARM void func_020942ac(char* obj);
#endif

// USA: func_02093980
ARM void ClearRegion02093980(char* obj) {
    memset(obj, 0, kClearSize);
    *(short*)(obj + kHalfOffset) = -1;
    *(char*)(obj + kSignedByteOffset) = -1;
    *(char*)(obj + kFlagOffset) = 0;
}
