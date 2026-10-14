#include <globaldefs.h>

// USA: func_02085204
ARM int TestBit11At0x2f4_02085204(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 20) >> 31) != 0;
}
