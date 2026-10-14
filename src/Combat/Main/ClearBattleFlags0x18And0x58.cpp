#include <globaldefs.h>

// USA: func_020880e4
ARM void ClearBattleFlags0x18And0x58_020880e4(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x18) &= ~0x1;
    *(int*)(base + 0x58) &= ~0x7000000;
    base[0x76] = 0;
    base[0x99] = 0;
}
