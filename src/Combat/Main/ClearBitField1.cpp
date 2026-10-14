#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
int CheckField0NonZero_0202b7d8(int* obj);

// USA: func_020e3748
ARM void ClearBitField1_020e3748(unsigned char* obj, int bit) {
    if (CheckField0NonZero_0202b7d8((int*)func_0202ae18())) {
        obj[1] &= ~(1 << bit);
    }
}
