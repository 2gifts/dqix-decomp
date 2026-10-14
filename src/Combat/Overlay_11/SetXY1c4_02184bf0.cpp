#include <globaldefs.h>

// USA: func_ov011_02184bf0
ARM void SetXY1c4_02184bf0(void* obj, int x, int y) {
    *(short*)((char*)obj + 0x1c4) = x;
    *(short*)((char*)obj + 0x1c6) = y;
}
