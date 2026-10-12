#include <globaldefs.h>

#if defined(jpn)
enum { kClearOffset = 0x729e };
#else
enum { kClearOffset = 0x74de };
#endif

#include "std_library_functions.h"

#if defined(jpn)
#define Clear0x20BytesAt0x74de func_02011e00
extern "C" ARM void* func_02011e00(unsigned char* obj);
#endif

// USA: func_02012084
ARM void* Clear0x20BytesAt0x74de(unsigned char* obj) {
    return memset(obj + kClearOffset, 0, 0x20);
}
