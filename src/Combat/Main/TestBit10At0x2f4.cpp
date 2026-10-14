#include <globaldefs.h>

// USA: func_020851d8
ARM int TestBit10At0x2f4_020851d8(unsigned char* obj) {
    if (*(short*)(obj + 0x2ac) <= 0) {
        return 0;
    }
    return (((unsigned int)(*(int*)(obj + 0x2f4)) << 0x15) >> 0x1f) != 0;
}
