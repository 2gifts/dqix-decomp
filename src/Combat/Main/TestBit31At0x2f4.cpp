#include <globaldefs.h>

// USA: func_02085720
ARM int TestBit31At0x2f4_02085720(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return ((unsigned int)*(int*)(obj + 0x2f4) >> 31) != 0;
}
