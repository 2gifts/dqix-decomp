#include <globaldefs.h>

#if defined(jpn)
enum { ARRAY_BYTE_OFFSET = 0x7d2 };
#else
enum { ARRAY_BYTE_OFFSET = 0x902 };
#endif

// USA: func_020465f0
ARM void SetByteInRange(unsigned char* base, int index, unsigned char value) {
    if (index < 0) {
        return;
    }
    if (index < 0x10) {
        (base + index)[ARRAY_BYTE_OFFSET] = value;
    }
}
