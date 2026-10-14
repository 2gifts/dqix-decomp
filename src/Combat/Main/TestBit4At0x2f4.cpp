#include <globaldefs.h>

// USA: func_02085128
ARM int TestBit4At0x2f4_02085128(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 27) >> 31) != 0;
}
