#include <globaldefs.h>

// USA: func_020d76d8
ARM void ClearFlagBit_020d76d8(unsigned char* base, int bit) {
    base += 0xa00;
    if (bit >= 0xc0) {
        bit -= 0xbc;
    }
    *(unsigned short*)(base + 0x26) &= ~(1 << bit);
}
