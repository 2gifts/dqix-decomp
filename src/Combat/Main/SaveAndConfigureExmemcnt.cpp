#include <globaldefs.h>

#define EXMEMCNT (*(volatile unsigned short*)0x4000204)

// USA: func_020d1468
ARM void SaveAndConfigureExmemcnt_020d1468(int* out) {
    out[0] = (EXMEMCNT & 0xc) >> 2;
    out[1] = (EXMEMCNT & 0x10) >> 4;
    EXMEMCNT = (EXMEMCNT & ~0xc) | 0xc;
    EXMEMCNT = EXMEMCNT & ~0x10;
}
