#include <globaldefs.h>

// USA: func_02087cfc
ARM void ClearBattleFlags0x14And0x58_02087cfc(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x14) &= ~0x8000;
    *(int*)(base + 0x58) &= ~0x38000;
    base[0x73] = 0;
    base[0x96] = 0;
}
