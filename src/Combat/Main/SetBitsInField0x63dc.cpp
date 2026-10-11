#include <globaldefs.h>

// USA: func_02011b3c
ARM void SetBitsInField0x63dc(void* obj, unsigned char mask) {
    unsigned char* base = (unsigned char*)obj;
#if defined(jpn)
    (base + 0x6000)[0x17c] |= mask;
#else
    (base + 0x6000)[0x3dc] |= mask;
#endif
}
