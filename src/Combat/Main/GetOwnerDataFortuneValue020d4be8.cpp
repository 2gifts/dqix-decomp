#include <globaldefs.h>

ARM void CopyFrom027ffcf4_020c99ac(void* dst);

// USA: func_020d4be8
#pragma optimize_for_size off
ARM unsigned short GetOwnerDataFortuneValue020d4be8() {
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
    sum = (unsigned short)(sum + *(int*)0x27ffc3c);
    return ((unsigned short)(sum * 13) % 10) + 30;
}
