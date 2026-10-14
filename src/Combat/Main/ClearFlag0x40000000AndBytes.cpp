#include <globaldefs.h>

// USA: func_02088b84
ARM void ClearFlag0x40000000AndBytes_02088b84(unsigned char* obj) {
    ((int*)obj)[5] &= ~0x40000000;
    obj[0x68] = 0;
    obj[0x8b] = 0;
}
