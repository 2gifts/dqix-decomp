#include <globaldefs.h>

void ClearFlag0x10AndBytes_02088d4c(unsigned char* obj);

// USA: func_02088ccc
ARM void SetFlag0x8ClearFlag0x10_02088ccc(unsigned char* obj) {
    obj[0x6b] = 5;
    obj[0x8e] = 0;
    *(int*)(obj + 0x18) |= 0x8;
    ClearFlag0x10AndBytes_02088d4c(obj);
}
