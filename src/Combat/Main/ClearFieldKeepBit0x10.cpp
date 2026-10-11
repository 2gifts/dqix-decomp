#include <globaldefs.h>

// USA: func_02011af0
ARM void ClearFieldKeepBit0x10(void* obj) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    int keep = ((base + 0x6000)[0x17c] & 0x10) != 0;
#else
    int keep = ((base + 0x6000)[0x3dc] & 0x10) != 0;
#endif
#if defined(jpn)
    (base + 0x6000)[0x17c] = 0;
#else
    (base + 0x6000)[0x3dc] = 0;
#endif
    if (keep) {
#if defined(jpn)
        (base + 0x6000)[0x17c] |= 0x10;
#else
        (base + 0x6000)[0x3dc] |= 0x10;
#endif
    }
}
