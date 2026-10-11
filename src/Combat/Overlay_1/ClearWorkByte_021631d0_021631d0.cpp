#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void* obj, int val);

// USA: func_ov001_021631d0
ARM int ClearWorkByte_021631d0_021631d0(void* ctx) {
#if defined(jpn)
    enum { queueOffset = 0x524, fieldOffset = 0x101 };
#else
    enum { queueOffset = 0x734, fieldOffset = 0x105 };
#endif
    unsigned char* self = (unsigned char*)func_ov017_0218b5b0();
    unsigned char* work = *(unsigned char**)(self + 0x3000 + queueOffset);
    unsigned char v = work[fieldOffset];
    work[fieldOffset] = 0;
    func_ov017_021d6134(ctx, v);
    return 1;
}
