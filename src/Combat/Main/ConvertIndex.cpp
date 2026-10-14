#include <globaldefs.h>

extern signed char data_020e6ddc;

// USA: func_02012f68
ARM int ConvertIndex_02012f68(int x) {
    x += -20000;
    if (x < 0) return -1;
    if (x >= 0x3c && x <= 0x3f) {
        x = (&data_020e6ddc)[x - 0x3c];
    }
    if (x >= 0x3c) return -1;
    return x;
}
