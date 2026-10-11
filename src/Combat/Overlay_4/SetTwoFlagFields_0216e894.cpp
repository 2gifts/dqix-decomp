#include <globaldefs.h>

int GetGlobalField0x1c020421a0(void);

// USA: func_ov004_0216e894  (semantic: SetTwoFlagFields_0216e894)
extern "C" ARM int func_ov004_0216e894(void) {
#if defined(jpn)
    enum { firstOffset = 0x7fb, secondOffset = 0x7df };
#else
    enum { firstOffset = 0x9ca, secondOffset = 0x9af };
#endif
    int g = GetGlobalField0x1c020421a0();
    g += 0x1000;
    *(unsigned char*)(g + firstOffset) = 1;
    *(unsigned char*)(g + secondOffset) = 1;
    return 0;
}
