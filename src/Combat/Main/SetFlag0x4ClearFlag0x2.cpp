#include <globaldefs.h>

void ClearFlag0x2AndBytes_02088c38(unsigned char* obj);

// USA: func_02088c74
ARM void SetFlag0x4ClearFlag0x2_02088c74(unsigned char* obj) {
    obj[0x6d] = 5;
    obj[0x90] = 0;
    *(int*)(obj + 0x18) |= 0x4;
    ClearFlag0x2AndBytes_02088c38(obj);
}
