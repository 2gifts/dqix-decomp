#include <globaldefs.h>

// USA: func_0204bdd8
ARM int CheckLow5BitsEqual2_0204bdd8(unsigned short* obj) {
    return (obj[1] & 0x1f) == 2;
}
