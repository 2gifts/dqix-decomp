#include <globaldefs.h>

#if defined(jpn)
enum { ARRAY_BYTE_OFFSET = 0x7c1 };
#else
enum { ARRAY_BYTE_OFFSET = 0x8f1 };
#endif

// USA: func_020465d8
ARM void SetByteAtIndex(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[ARRAY_BYTE_OFFSET] = value;
    }
}
