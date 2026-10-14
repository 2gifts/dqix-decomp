#include <globaldefs.h>

// USA: func_02088914
ARM void ClearFlag0x200AndBytes_02088914(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x200;
    obj[0x61] = 0;
    obj[0x84] = 0;
}
