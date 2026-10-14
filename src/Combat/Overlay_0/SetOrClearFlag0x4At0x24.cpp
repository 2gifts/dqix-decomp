#include <globaldefs.h>

// USA: func_ov000_02174a38
ARM void SetOrClearFlag0x4At0x24_ov000_02174a38(void* obj, int cond) {
    int v = *((unsigned char*)obj + 0x24);
    if (cond) {
        v |= 0x4;
    } else {
        v &= ~0x4;
    }
    *((unsigned char*)obj + 0x24) = v;
}
