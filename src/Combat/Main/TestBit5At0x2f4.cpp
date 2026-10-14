#include <globaldefs.h>

// USA: func_02085154
ARM int TestBit5At0x2f4_02085154(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 26) >> 31) != 0;
}
