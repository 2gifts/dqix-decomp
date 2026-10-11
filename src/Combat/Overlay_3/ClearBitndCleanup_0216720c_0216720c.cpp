// JPN: func_ov003_021670ec
// USA: func_ov003_0216720c
#include <globaldefs.h>
#if defined(jpn)
enum { kRegion464 = 0x28c };
enum { kRegion328 = 0x210 };
#else
enum { kRegion464 = 0x464 };
enum { kRegion328 = 0x328 };
#endif

extern "C" void func_0204b088(void*, int);

ARM void ClearBitndCleanup_0216720c_0216720c(char* obj) {
    if (*(int*)(obj + kRegion464) & 0x40000) {
        func_0204b088(*(char**)(obj + kRegion328) + 0x40, 0);
        *(int*)(obj + kRegion464) &= ~0x40000;
    }
}
