#include <globaldefs.h>

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void func_ov017_021d6134(void*, int);

// USA: func_ov001_02161a1c
ARM int DispatchFieldOrDefault_02161a1c(void* ctx) {
#if defined(jpn)
    enum { queueOffset = 0x524, objectOffset = 0x15c, flagOffset = 0x160 };
#else
    enum { queueOffset = 0x734, objectOffset = 0x160, flagOffset = 0x164 };
#endif
    char* p = (char*)func_ov017_0218b5b0() + 0x3000;
    char* q = *(char**)(p + queueOffset);
    int v = *(int*)(q + objectOffset);
    if (v == 0) {
        func_ov017_021d6134(ctx, 1);
    } else {
        func_ov017_021d6134(ctx, *(unsigned char*)(q + flagOffset));
    }
    return 1;
}
