#include <globaldefs.h>

// USA: func_020850d0
ARM int TestBit2At0x2f4_020850d0(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 29) >> 31) != 0;
}
