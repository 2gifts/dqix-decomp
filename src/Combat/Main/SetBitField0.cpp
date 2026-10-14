#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

// USA: func_020e36c4
ARM void SetBitField0_020e36c4(unsigned char* obj, int bit) {
    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
        obj[0] |= 1 << bit;
    }
}
