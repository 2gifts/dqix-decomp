#include <globaldefs.h>

// USA: func_020850fc
ARM int TestBit3At0x2f4_020850fc(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) return 0;
    return (((unsigned int)*(int*)(obj + 0x2f4) << 28) >> 31) != 0;
}
