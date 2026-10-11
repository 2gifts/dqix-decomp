#include <globaldefs.h>
#if defined(jpn)
#define REGION_FIELD_0 0x1f00
#define REGION_FIELD_1 0xaa
#else
#define REGION_FIELD_0 0x1d00
#define REGION_FIELD_1 0x72
#endif


// USA: func_ov023_021f1818  (semantic: SetSubEngineModeFlag_021f1818)
extern "C" ARM void func_ov023_021f1818(char* obj, int enable) {
    obj += REGION_FIELD_0;
    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    if (enable) {
        *(unsigned short*)(obj + REGION_FIELD_1) |= 0x80;
        *reg = (*reg & ~0x1f00) | 0x200;
    } else {
        *(unsigned short*)(obj + REGION_FIELD_1) &= ~0x80;
        *reg = (*reg & ~0x1f00) | 0x1700;
    }
}
