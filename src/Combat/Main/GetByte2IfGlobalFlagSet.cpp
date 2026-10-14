#include <globaldefs.h>

extern "C" int* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

// USA: func_020e37e8
ARM int GetByte2IfGlobalFlagSet_020e37e8(unsigned char* p) {
    if (CheckField0NonZero_0202b7d8(func_0202ae18())) {
        return p[2];
    }
    return 1;
}
