#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void* p);
extern unsigned short data_02114e30;

// USA: func_ov002_02161b48
ARM int CheckFlagOrThreshold_02161b48(char* base, int flag) {
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2)) {
        return 1;
    }
    if (flag) {
        if (func_0205d97c(base + 0xec8) == 2) {
            return 1;
        }
    }
    return 0;
}
