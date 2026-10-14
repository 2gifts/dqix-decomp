#include <globaldefs.h>

// USA: func_02085644
ARM int TestBit26At0x2f4_02085644(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 5) >> 31) != 0;
}
