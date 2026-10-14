#include <globaldefs.h>

// USA: func_02020028
ARM void SetOrClearFlagBit0x55d_02020028(unsigned char* base, int set, int bit) {
    if (bit < 0) {
        if (set) base[0x55d] = 0xf;
        else base[0x55d] = 0;
    } else {
        if (set) base[0x55d] |= (1 << bit);
        else base[0x55d] &= ~(1 << bit);
    }
}
