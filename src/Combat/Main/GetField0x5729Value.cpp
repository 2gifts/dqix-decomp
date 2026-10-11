#include <globaldefs.h>

// USA: func_02010750
// JPN: func_020105ac
ARM unsigned char GetField0x5729Value(char* obj) {
#if defined(jpn)
    return *(unsigned char*)(obj + 0x54c9);
#else
    return *(unsigned char*)(obj + 0x5729);
#endif
}
