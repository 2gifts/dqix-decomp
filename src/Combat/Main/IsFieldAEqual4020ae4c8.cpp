#include <globaldefs.h>

extern "C" int func_ov017_0218b5b0(void);

// USA: func_020ae4c8
ARM bool IsFieldAEqual4020ae4c8() {
    int base = func_ov017_0218b5b0();
#if defined(jpn)
    int p = *(int*)(base + 0x3524);
#else
    int p = *(int*)(base + 0x3734);
#endif
    return *(unsigned short*)(p + 0xa) == 4;
}
