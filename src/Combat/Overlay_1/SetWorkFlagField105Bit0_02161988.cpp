#include <globaldefs.h>

extern "C" void* func_02012fe4(void);
extern "C" int func_ov017_021d60f4(void* obj);

// USA: func_ov001_02161988  (semantic: SetWorkFlagField105Bit0_02161988)
extern "C" ARM int func_ov001_02161988(void* obj) {
#if defined(jpn)
    enum { fieldOffset = 0x125 };
#else
    enum { fieldOffset = 0x105 };
#endif
    unsigned char* work = (unsigned char*)func_02012fe4();
    int cond = func_ov017_021d60f4(obj);
    if (cond != 0)
        work[fieldOffset] &= ~1;
    else
        work[fieldOffset] |= 1;
    return 1;
}
