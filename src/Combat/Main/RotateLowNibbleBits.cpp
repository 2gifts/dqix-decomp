#include <globaldefs.h>

// USA: func_0201a108
ARM void RotateLowNibbleBits_0201a108(void* obj, unsigned char* p, int mode) {
    unsigned char b0 = *p & 1;
    unsigned char b1 = (*p & 2) >> 1;
    unsigned char b2 = (*p & 4) >> 2;
    unsigned char b3 = (*p & 8) >> 3;
    switch (mode) {
    case 1: *p = b1 | (b2 << 1) | (b3 << 2) | (b0 << 3); break;
    case 2: *p = b2 | (b3 << 1) | (b0 << 2) | (b1 << 3); break;
    case 3: *p = b3 | (b0 << 1) | (b1 << 2) | (b2 << 3); break;
    }
}
