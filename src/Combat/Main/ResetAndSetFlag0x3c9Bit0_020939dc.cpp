#include <globaldefs.h>

extern "C" void func_020938f0(void* obj);

// USA: func_020939dc
ARM void ResetAndSetFlag0x3c9Bit0_020939dc(void* obj) {
    func_020938f0(obj);
#if defined(jpn)
    *((unsigned char*)obj + 0x139) = (*((unsigned char*)obj + 0x139) & ~1) | 1;
#else
    *((unsigned char*)obj + 0x3c9) = (*((unsigned char*)obj + 0x3c9) & ~1) | 1;
#endif
}
