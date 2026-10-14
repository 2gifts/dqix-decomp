#include <globaldefs.h>

void ClearFlag0x8AndBytes_02088cf4(unsigned char* obj);

// USA: func_02088d24
ARM void SetFlag0x10ClearFlag0x8_02088d24(unsigned char* obj) {
    obj[0x7b] = 5;
    obj[0x9e] = 0;
    *(int*)(obj + 0x18) |= 0x10;
    ClearFlag0x8AndBytes_02088cf4(obj);
}
