#include <globaldefs.h>

// USA: func_02088b14
ARM void SetFlag0x400000AndBytes_02088b14(unsigned char* obj) {
    obj[0x67] = 6;
    obj[0x8a] = 0;
    ((int*)obj)[5] |= 0x400000;
}
