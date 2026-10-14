#include <globaldefs.h>

// USA: func_020856f4
ARM int TestBit30At0x2f4_020856f4(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 1) >> 31) != 0;
}
