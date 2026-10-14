#include <globaldefs.h>

// USA: func_0202006c
ARM void SetFlagBits0x55e_0202006c(unsigned char* base, int bit) {
    int v;
    if (bit < 0) v = 0xf;
    else v = 1 << bit;
    base[0x55e] = v;
}
