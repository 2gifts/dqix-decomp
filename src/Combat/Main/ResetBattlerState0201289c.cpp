#include <globaldefs.h>

void ClearBytes0x50To0x53_02012780(unsigned char* obj);

// USA: func_0201289c
ARM void ResetBattlerState0201289c(unsigned char* obj) {
    *(int*)(obj + 0x30) = *(int*)(obj + 0x34) = -1;
    ClearBytes0x50To0x53_02012780(obj);
    *(int*)(obj + 0x48) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    obj[0x56] = 0;
    *(int*)(obj + 0x58) = 0;
    obj[0x5d] = 0;
    obj[0x5f] = 0;
}
