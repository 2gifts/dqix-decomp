#include <globaldefs.h>

// USA: func_02088c38
ARM void ClearFlag0x2AndBytes_02088c38(unsigned char* obj) {
    ((int*)obj)[6] &= ~0x2;
    obj[0x6c] = 0;
    obj[0x8f] = 0;
}
