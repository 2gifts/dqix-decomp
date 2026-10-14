#include <globaldefs.h>

// USA: _Z29GetDataTcmRegionBase_020c89e4v
ARM unsigned int GetDataTcmRegionBase_020c89e4(void) {
    unsigned int v;
    asm {
        mrc p15, 0, v, c9, c1, 0
    }
    v = v & 0xfffff000;
    return v;
}
