#include <globaldefs.h>

// USA: func_020857ec
ARM int TestBit3At0x2f8_020857ec(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f8) << 28) >> 31) != 0;
}
