#include <globaldefs.h>
#include "Graphics/GlyphMetrics.h"

extern "C" void func_020292ec(int a, int b, int c, int d, int e);
void PackRegister02029470(int a, int b, int c, int d, int e, int f);


// USA: func_02029384
ARM int SetupViewport02029384(int a0, int a1, int a2, int a3) {
    int mode = data_020ef74c.displayMode;

    if (mode == 2) {
        return 0;
    }
    if (mode == 4) {
        return 0;
    }

    *(volatile unsigned short*)0x4000060 = (*(volatile unsigned short*)0x4000060 & ~0x3000) | 0x4;
    *(volatile unsigned short*)0x4000340 = 0;
    *(volatile unsigned int*)0x40004a8 = 0x900000;

    PackRegister02029470(0, 1, 3, 0x3b, 0x12, 0);

    func_020292ec(a0 + 2, a1 + 2, a2 - 4, a3 - 4, 0);

    PackRegister02029470(0, 1, 3, 0, 0, 0);

    func_020292ec(a0, a1, a2, a3, 0x7fff);

    return 1;
}
