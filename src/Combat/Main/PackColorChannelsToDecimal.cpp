#include <globaldefs.h>

// USA: func_0204bea0
ARM int PackColorChannelsToDecimal_0204bea0(unsigned short* obj) {
    unsigned short v = obj[0];
    unsigned short r = v & 0x1f;
    unsigned short g = (v & 0x3e0) >> 5;
    unsigned short b = (v & 0x7c00) >> 10;
    return r * 100 + 20000 + g * 10 + b;
}
