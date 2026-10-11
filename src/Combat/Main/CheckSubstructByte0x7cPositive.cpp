#include <globaldefs.h>

#if defined(jpn)
enum { SIGNED_BYTE_OFFSET = 0x170 };
#else
enum { SIGNED_BYTE_OFFSET = 0x17c };
#endif

// USA: func_020535c8
ARM int CheckSubstructByte0x7cPositive(signed char* obj) {
    return obj[SIGNED_BYTE_OFFSET] > 0;
}
