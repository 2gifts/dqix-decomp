#include <globaldefs.h>

// USA: func_ov004_0215eb20
ARM unsigned short GetFlagBitFromField150_0215eb20(void* obj, int bit) {
#if defined(jpn)
    enum { objectOffset = 0x144, fieldOffset = 0x8bc };
#else
    enum { objectOffset = 0x150, fieldOffset = 0x954 };
#endif
    void* p = *(void**)((char*)obj + objectOffset);
    unsigned short v = *(unsigned short*)((char*)p + fieldOffset);
    return (unsigned short)(v & (1 << bit));
}
