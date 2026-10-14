#include <globaldefs.h>

// USA: func_0208902c
ARM void ResetFields14And18KeepFlag0x4(unsigned char* obj, int val) {
    unsigned int x = *(unsigned int*)(obj + 0x14);
    int had4 = 0;
    if (x & 0x4) {
        had4 = 1;
    }
    *(unsigned int*)(obj + 0x14) = 0;
    *(unsigned int*)(obj + 0x18) = 0;
    if (had4) {
        *(unsigned int*)(obj + 0x14) |= 0x4;
    }
    *(unsigned short*)obj = val;
}
