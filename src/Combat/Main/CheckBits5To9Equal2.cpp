#include <globaldefs.h>

// USA: func_0204be20
// JPN: func_0204cc40
ARM int CheckBits5To9Equal2(unsigned short* obj) {
    return ((obj[1] & 0x3e0) >> 5) == 2;
}
