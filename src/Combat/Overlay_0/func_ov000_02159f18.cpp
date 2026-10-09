#include <globaldefs.h>

// USA: func_ov000_02159f18
extern "C" ARM int func_ov000_02159f18(void* unused, unsigned long long bits, unsigned int bit) {
    if (bit > 31) {
        bits &= ((unsigned long long)(1 << (bit - 31)) << 32) & 0xFFFFFFFF00000000ULL;
    } else {
        bits &= (unsigned long long)(1 << bit) & 0xFFFFFFFFULL;
    }
    return bits != 0;
}
