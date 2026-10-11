#include <globaldefs.h>

// USA: func_02039d7c
ARM unsigned char GetByte0x26c(char* obj) {
#if defined(jpn)
    return obj[0x260];
#else
    return obj[0x26c];
#endif
}
