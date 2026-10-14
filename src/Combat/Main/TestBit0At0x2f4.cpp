#include <globaldefs.h>

// USA: func_02085078
ARM int TestBit0At0x2f4_02085078(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return ((unsigned int)((*(int*)(obj + 0x2f4)) << 31) >> 31) != 0;
}
