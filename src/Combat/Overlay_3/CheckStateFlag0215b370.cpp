#include <globaldefs.h>

extern "C" int func_0205d97c(void* p);
int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern unsigned short data_02114e30;

// USA: func_ov003_0215b370
ARM int CheckStateFlag0215b370(void* obj, int flag) {
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 2) != 0) return 1;
    if (flag == 0) goto ret0;
    if (func_0205d97c((char*)obj + 0xf4) == 2) return 1;
ret0:
    return 0;
}
