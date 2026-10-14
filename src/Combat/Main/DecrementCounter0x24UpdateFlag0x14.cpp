#include <globaldefs.h>

// USA: func_02087704
ARM void DecrementCounter0x24UpdateFlag0x14_02087704(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    base[0x24] = base[0x24] - 1;
    if (base[0x24] == 3) {
        *(int*)(base + 0x14) &= ~0x1000000;
        base[0x24] = 0;
        *(int*)(base + 0x14) |= 0x800000;
        base[0x24] = 3;
    }
    if (base[0x24] != 0) {
        return;
    }
    base[0x24] = 0;
    *(int*)(base + 0x14) &= ~0x800000;
    base[0x24] = 0;
}
