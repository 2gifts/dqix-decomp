#include <globaldefs.h>

ARM void CopyFrom027ffcf4_020c99ac(void* dst);

// USA: func_020d4b58
#pragma optimize_for_size off
ARM unsigned short GetOwnerDataFortuneValue_020d4b58() {
    unsigned char buf[8];
    CopyFrom027ffcf4_020c99ac(buf);
    unsigned char* p = buf;
    unsigned short sum;
    int i;
    i = 0, sum = 0;
    do {
        unsigned char b = *p++;
        i++;
        sum = (unsigned short)(sum + b);
    } while (i < 6);
    unsigned short combined = (unsigned short)(sum + *(int*)0x27ffc3c);
    unsigned short mul7 = (unsigned short)(combined * 7);
    return (mul7 % 20) + 200;
}
