#include <globaldefs.h>

// USA: func_020133b4
ARM void SetFlag0x80_020133b4(void* obj, int value) {
    int x = ((signed char*)obj)[4];
    if (value) {
        x |= 0x80;
    } else {
        x &= ~0x80;
    }
    ((unsigned char*)obj)[4] = x;
}
