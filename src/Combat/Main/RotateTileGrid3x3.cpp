#include <globaldefs.h>
#include "std_library_functions.h"

void RotateLowNibbleBits_0201a108(void* obj, unsigned char* p, int mode);

// USA: func_02019f6c
ARM void RotateTileGrid3x3_02019f6c(void* obj, unsigned char* buf, int mode) {
    unsigned char tmp[9];
    int i;
    memcpy(tmp, buf, 9);

    switch (mode) {
    case 1:
        buf[0] = tmp[2];
        buf[1] = tmp[5];
        buf[2] = tmp[8];
        buf[3] = tmp[1];
        buf[4] = tmp[4];
        buf[5] = tmp[7];
        buf[6] = tmp[0];
        buf[7] = tmp[3];
        buf[8] = tmp[6];
        for (i = 0; i < 9; i++) {
            RotateLowNibbleBits_0201a108(obj, buf + i, 1);
        }
        break;
    case 2:
        buf[0] = tmp[8];
        buf[1] = tmp[7];
        buf[2] = tmp[6];
        buf[3] = tmp[5];
        buf[4] = tmp[4];
        buf[5] = tmp[3];
        buf[6] = tmp[2];
        buf[7] = tmp[1];
        buf[8] = tmp[0];
        for (i = 0; i < 9; i++) {
            RotateLowNibbleBits_0201a108(obj, buf + i, 2);
        }
        break;
    case 3:
        buf[0] = tmp[6];
        buf[1] = tmp[3];
        buf[2] = tmp[0];
        buf[3] = tmp[7];
        buf[4] = tmp[4];
        buf[5] = tmp[1];
        buf[6] = tmp[8];
        buf[7] = tmp[5];
        buf[8] = tmp[2];
        for (i = 0; i < 9; i++) {
            RotateLowNibbleBits_0201a108(obj, buf + i, 3);
        }
        break;
    }
}
