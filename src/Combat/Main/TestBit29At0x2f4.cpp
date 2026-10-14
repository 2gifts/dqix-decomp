#include <globaldefs.h>

// USA: func_020856c8
ARM int TestBit29At0x2f4_020856c8(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 2) >> 31) != 0;
}
