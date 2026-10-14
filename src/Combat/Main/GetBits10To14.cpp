#include <globaldefs.h>

// USA: func_0204be90
ARM int GetBits10To14_0204be90(unsigned short* obj) {
    return (obj[1] & 0x7c00) >> 10;
}
