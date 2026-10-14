#include <globaldefs.h>

// USA: func_02085794
ARM int TestBit1At0x2f8_02085794(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f8) << 30) >> 31) != 0;
}
