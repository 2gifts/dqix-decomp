#include <globaldefs.h>

struct Bits64_0215fd90 {
    unsigned long long value;
};

// USA: func_ov000_0215fd90
extern "C" ARM int func_ov000_0215fd90(struct Bits64_0215fd90* bits, unsigned int n) {
    unsigned long long result;
    if (n > 31) {
        result = bits->value & (((unsigned long long)(1 << (n - 31)) << 32) & 0xFFFFFFFF00000000ULL);
    } else {
        result = bits->value & ((long long)(1 << n) & 0xFFFFFFFFULL);
    }
    return result != 0;
}
