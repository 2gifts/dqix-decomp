#include <globaldefs.h>

// USA: func_0204bdc0
ARM int CheckLow5BitsEqual1_0204bdc0(unsigned short* obj) {
    return (obj[1] & 0x1f) == 1;
}
