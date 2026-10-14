#include <globaldefs.h>

void ClearBattleFlag0x14Bit4_02088390(void* obj);
void ClearFlag0x20AndBytes_020883fc(void* obj);

// USA: func_0208826c
ARM void ResetStateFields0208826c(unsigned char* obj) {
    *(int*)(obj + 0x14) &= ~0x800000;
    obj[0x24] = 0;
    ClearBattleFlag0x14Bit4_02088390(obj);
    *(int*)(obj + 0x14) &= ~0x80000;
    *(unsigned short*)(obj + 0x22) &= ~0x3c;
    ClearFlag0x20AndBytes_020883fc(obj);
    obj[0x21] = 0;
    *(int*)(obj + 0x18) &= ~0x20;
    obj[0x5c] = 3;
    obj[0x7f] = 0;
    *(int*)(obj + 0x14) |= 0x8;
}
