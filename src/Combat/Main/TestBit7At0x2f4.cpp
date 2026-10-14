#include <globaldefs.h>

// USA: func_020851ac
ARM int TestBit7At0x2f4_020851ac(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 24) >> 31) != 0;
}
