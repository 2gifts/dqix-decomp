#include <globaldefs.h>

extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

// USA: func_020e3778
ARM void SetByte2IfGlobalFlagSet_020e3778(unsigned char* p) {
    if (CheckField0NonZero_0202b7d8(func_0202ae18())) {
        p[2] = 1;
    }
}
