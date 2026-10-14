#include <globaldefs.h>

extern "C" int func_020d135c(void);
int GetState0x27ffc30Bit0_020d1344(void);

// USA: func_020d131c
ARM int IsReadyAndBit0Clear_020d131c(void) {
    if (func_020d135c() != 0) {
        if (GetState0x27ffc30Bit0_020d1344() == 0) return 1;
    }
    return 0;
}
