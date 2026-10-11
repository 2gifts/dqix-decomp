#include <globaldefs.h>

extern "C" void _Z30SetDispcntModeAndFlags020c391ciii(int mode, int flagsA, int valB);

struct S0218d034 { char pad0[0x4]; int field4; 
#if defined(jpn)
 char pad1[0xc - 0x8];
#else
 char pad1[0x30 - 0x8];
#endif
 int field30; };
extern S0218d034 data_ov016_0219d144;
extern char data_027e0000;

// USA: func_ov016_0218d034  (semantic: ToggleAndConfigureDisplay_0218d034)
extern "C" ARM void func_ov016_0218d034(void) {
    if (data_ov016_0219d144.field30 == 0) {
        data_ov016_0219d144.field30 = 1;
        if (data_ov016_0219d144.field4 == 0) {
            _Z30SetDispcntModeAndFlags020c391ciii(6, 0, 0);
            *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x1000;
        } else {
            _Z30SetDispcntModeAndFlags020c391ciii(2, 0, 0);
            *(volatile unsigned int*)0x4001000 = (*(volatile unsigned int*)0x4001000 & ~0x1f00) | 0x400;
        }
        data_ov016_0219d144.field4 ^= 1;
    }
    *(unsigned int*)((char*)&data_027e0000 + 0x3000 + 0xff8) |= 1;
}
