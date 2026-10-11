#include <globaldefs.h>

// USA: func_ov017_0218d4d0
ARM void ClearFlagBit_0218d4d0(void* obj, int bit) {
    unsigned char* p = (unsigned char*)obj
#if defined(jpn)
        + 0x4111;
#else
        + 0x4331;
#endif
    *p &= ~(1 << bit);
}
