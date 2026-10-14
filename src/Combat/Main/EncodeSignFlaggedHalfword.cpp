#include <globaldefs.h>

// USA: func_020c39a0
ARM void EncodeSignFlaggedHalfword_020c39a0(short* out, int value) {
    if (value == 0) {
        *out = 0;
    } else if (value > 0) {
        *out = value | 0x4000;
    } else {
        *out = (-value) | 0x8000;
    }
}
