#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear_02012444(unsigned short* obj, int mask);
extern unsigned char data_02114e54;
extern unsigned short data_02114e30;

// USA: func_ov006_02158c70
ARM int CheckFlagOrByte55_02158c70() {
    int result = 0;
    int b = *(&data_02114e54 + 0x55);
    if (TestFlag0SetAndFlag1Clear_02012444(&data_02114e30, 0x7f3) || b) {
        result = 1;
    }
    return result;
}
