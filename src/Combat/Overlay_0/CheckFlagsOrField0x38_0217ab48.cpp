#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern "C" int func_0205d97c(int);
extern unsigned short data_02114e30;

// USA: func_ov000_0217ab48
ARM int CheckFlagsOrField_0217ab48_0217ab48(void* objRaw) {
    char* obj = (char*)objRaw;
    int a = TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x802);
    int b = func_0205d97c(*(int*)(obj + 0x38));
    if ((a | (b == 2)) != 0) {
        return 1;
    }
    return 0;
}
