#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern "C" int func_0205d97c(void*);
extern unsigned short data_02114e30;

// USA: func_ov000_0217c5f4
ARM int CheckFlagsOrField_0217c5f4_0217c5f4(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x802);
    int b = func_0205d97c(obj + 0x188);
    if ((a | (b == 2)) != 0) {
        return 1;
    }
    return 0;
}
