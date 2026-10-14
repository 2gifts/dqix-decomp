#include <globaldefs.h>

// USA: func_0204be78
ARM int CheckBits5To9NonZero_0204be78(unsigned short* obj) {
    return ((obj[1] & 0x3e0) >> 5) != 0;
}
