#include <globaldefs.h>

struct Bits64_02159eac {
    unsigned long long value;
};

// USA: func_ov000_02159eac
extern "C" ARM void func_ov000_02159eac(void* unused, struct Bits64_02159eac* bits, unsigned int bit) {
    if (bit > 31) {
        bits->value |= ((unsigned long long)(1 << (bit - 31)) << 32) & 0xFFFFFFFF00000000ULL;
    } else {
        bits->value |= (unsigned long long)(1 << bit) & 0xFFFFFFFFULL;
    }
}
