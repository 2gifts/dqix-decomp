#include <globaldefs.h>

extern "C" long long func_020c30ac(unsigned int, unsigned int);
extern "C" long long func_020c3194(unsigned int, unsigned int);

// USA: func_020c3260
extern "C" ARM long long func_020c3260(int x) {
    long long m;
    if (x < 0) {
        return -func_020c3260(-x);
    }
    m = (long long)x * 0x145F306DDLL;
    int hi = (int)(m >> 44);
    unsigned long long v = (unsigned long long)((m >> 12) & 0xFFFFFFFFULL);
    if (hi & 1) {
        v = 0x100000000ULL - v;
    }
    long long r;
    if ((hi + 1) & 2) {
        r = func_020c3194((unsigned int)v, (unsigned int)(v >> 32));
    } else {
        r = func_020c30ac((unsigned int)v, (unsigned int)(v >> 32));
    }
    if ((hi & 7) <= 3) {
        return r;
    }
    return -r;
}
