#include <globaldefs.h>

ARM void CopyFrom027ffcf4_020c99ac(void* dst);

// USA: func_ov027_021dc618  (semantic: ComputeChecksumMod20_021dc618)
#pragma optimize_for_size off
extern "C" ARM unsigned int func_ov027_021dc618() {
    unsigned char buf[8];
    CopyFrom027ffcf4_020c99ac(buf);
    unsigned char* p = buf;
    unsigned int sum;
    int i;
    i = 0, sum = 0;
    do {
        sum += *p++;
        i++;
    } while (i < 6);
    unsigned int combined = sum + *(unsigned int*)0x27ffc3c;
    unsigned int mul7 = combined * 7;
    return mul7 % 20;
}
