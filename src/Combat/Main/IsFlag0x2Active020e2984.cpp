#include <globaldefs.h>

extern unsigned short data_02114e30;

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);

// USA: func_020e2984
ARM int IsFlag0x2Active020e2984(struct Outer020e28dc* window) {
    return TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2) != 0;
}
