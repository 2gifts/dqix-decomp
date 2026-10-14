#include <globaldefs.h>

struct Bits0x2f8_02085768 { unsigned int b0 : 1; };

// USA: func_02085768
ARM int TestBit0At0x2f8_02085768(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return ((struct Bits0x2f8_02085768*)(obj + 0x2f8))->b0 != 0;
}
