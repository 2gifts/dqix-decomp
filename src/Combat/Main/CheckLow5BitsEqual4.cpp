#include <globaldefs.h>

// USA: func_0204be08
ARM int CheckLow5BitsEqual4_0204be08(unsigned short* obj) {
    return (obj[1] & 0x1f) == 4;
}
