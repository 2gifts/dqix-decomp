#include <globaldefs.h>

#if defined(jpn)
enum { kClearOffset = 0x729e };
#else
enum { kClearOffset = 0x74de };
#endif

#include "std_library_functions.h"

// USA: func_02012084
ARM void* Clear0x20BytesAt0x74de_02012084(unsigned char* obj) {
    return memset(obj + kClearOffset, 0, 0x20);
}
