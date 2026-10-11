#include <globaldefs.h>

extern "C" void func_ov023_021dfb4c(void*);

#if defined(jpn)
#define MODE_OFFSET 0x6f9
#define FLAGS_OFFSET 0x6f0
#else
#define MODE_OFFSET 0x77d
#define FLAGS_OFFSET 0x774
#endif

// JPN: func_ov023_021e00ec
// USA: func_ov023_021dfad8  (semantic: UpdateCaptureBit_021dfad8)
extern "C" ARM void func_ov023_021dfad8(char* obj) {
    func_ov023_021dfb4c(obj);
    if (*(signed char*)(obj + MODE_OFFSET) != 2) return;
    unsigned short flags = *(unsigned short*)(obj + FLAGS_OFFSET);
    volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
    if (flags & 0x800) {
        unsigned int f = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((f | 1) << 8);
    } else {
        unsigned int f = (*reg & 0x1f00) >> 8;
        *reg = (*reg & ~0x1f00) | ((f & ~1) << 8);
    }
}
