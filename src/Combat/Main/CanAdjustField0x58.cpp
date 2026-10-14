#include <globaldefs.h>

// USA: func_0208776c
ARM int CanAdjustField0x58_0208776c(void* obj, int dir) {
    unsigned char* base = (unsigned char*)obj;
    if (*(int*)(base + 0x14) & 1) {
        return 0;
    }
    if (dir == 0) {
        int v = (*(int*)(base + 0x58) << 29) >> 29;
        if (v < 2) {
            return 1;
        }
    } else {
        int v = (*(int*)(base + 0x58) << 29) >> 29;
        if (v > -2) {
            return 1;
        }
    }
    return 0;
}
