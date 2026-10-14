#include <globaldefs.h>

#if defined(jpn)
enum { FLAG_BYTE_OFFSET = 0x17c };
#else
enum { FLAG_BYTE_OFFSET = 0x3dc };
#endif

// USA: func_02011b50
ARM int CheckBitsInField0x63dc_02011b50(void* obj, int mask) {
    unsigned char* base = (unsigned char*)obj;
    return ((base + 0x6000)[FLAG_BYTE_OFFSET] & mask) != 0;
}
