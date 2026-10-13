#include <globaldefs.h>

#define POWCNT (*(volatile unsigned short*)0x04000304)

// USA: func_ov011_02187f4c  (semantic: Trans_02187f4c)
extern "C" ARM void func_ov011_02187f4c(unsigned int sel) {
    POWCNT = (unsigned short)((POWCNT & ~0x8000) | (sel << 15));
}
