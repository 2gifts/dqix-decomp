#include <globaldefs.h>

// USA: func_020850a4
ARM int TestBit1At0x2f4_020850a4(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 30) >> 31) != 0;
}
