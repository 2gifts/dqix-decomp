#include <globaldefs.h>

extern "C" ARM void func_ov031_022234d8(int a0, void* cb);
extern "C" extern int LoadToMainBG2ScreenData(int arg0, int arg1, unsigned int arg2);

extern int data_ov031_0224b988;

// USA: func_ov031_0222ab08  (semantic: FlushAndSetBgPriorities_0222ab08)
extern "C" ARM void func_ov031_0222ab08(void) {
    func_ov031_022234d8((int)&data_ov031_0224b988, (void*)LoadToMainBG2ScreenData);

    volatile unsigned short* subBg0 = (volatile unsigned short*)0x4001008;
    volatile unsigned short* bg0 = (volatile unsigned short*)0x4000008;
    volatile unsigned short* bg1 = (volatile unsigned short*)0x400000a;
    *subBg0 = (*subBg0 & ~3) | 3;
    *(subBg0 + 1) = (*(subBg0 + 1) & ~3) | 3;
    *bg0 = (*bg0 & ~3) | 3;
    *bg1 = (*bg1 & ~3) | 3;
    *(bg1 + 1) = (*(bg1 + 1) & ~3) | 3;
}
