#include <globaldefs.h>

#if defined(jpn)
#define FIELD_OFFSET 0x4111
#else
#define FIELD_OFFSET 0x4331
#endif

// JPN: func_ov017_0218e0cc
// USA: func_ov017_0218d4ec
ARM int HasFlagBit_0218d4ec(void* obj, int bit) {
    unsigned char* p = (unsigned char*)obj + FIELD_OFFSET;
    return *p & (1 << bit);
}
