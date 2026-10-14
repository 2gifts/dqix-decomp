#include <globaldefs.h>

// USA: func_0204bdf0
ARM int CheckLow5BitsEqual3_0204bdf0(unsigned short* obj) {
    return (obj[1] & 0x1f) == 3;
}
