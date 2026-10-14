#include <globaldefs.h>

// USA: func_0204be20
ARM int CheckBits5To9Equal2_0204be20(unsigned short* obj) {
    return ((obj[1] & 0x3e0) >> 5) == 2;
}
